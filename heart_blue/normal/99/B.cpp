#include <iostream> 
#include <list> 
#include <string>
#include <cmath>
#include <vector>
#include <fstream> 
using namespace std; 
class OK
{
public:
	int item;
	int num;

};
vector <OK> ok; 

template <class T> void change(T &a, T &b)// 
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
void quicksort(vector<OK> &S,int a,int b) // 
{
     int x = a;
	 int y = b;
	 int mid = S[(a+b)>>1].item;
     while (x <= y)
     {
           while (S[x].item < mid) x++;
           while (S[y].item > mid) y--;
           if (x <= y)
           {
              change(S[x], S[y]);
              x++;
              y--;
           }
     }
     if (x < b) quicksort(S, x, b);
     if (y > a) quicksort(S, a, y);
}
int main()
{      
	int n;  
	int avg;     
	long sum = 0;  
	cin >> n;    
	ok.resize(n);    
	for(int i = 0; i < n; i++)  
	{     
		cin >> ok[i].item;         
		sum += ok[i].item;       
		ok[i].num = i + 1;     
	}      
	avg = sum / n;   
	if(sum % n != 0)     
	{          
		cout << "Unrecoverable configuration." << endl;    
	}   
	else      
	{      
		quicksort(ok, 0, n - 1);   
		if(ok[0].item == ok[n-1].item)  
		{                  
			cout << "Exemplary pages." << endl;      
		}   
		else
		{
			int b,e;
			bool flag = true;
			b = e = -1;
			int ans;
			for(int i = 0; i < ok.size(); i++)
			{
				if(ok[i].item >= avg) break;
				
				if(b == -1)
				{
					b = ok[i].num;
					ans = avg - ok[i].item;
				}
				else 
				{
					flag = false;
					break;
				}
			}
			if(!flag)
			{
				cout << "Unrecoverable configuration." << endl;
			}
			else
			{
				for(int i = ok.size() - 1; i >= 0; i--)
				{
					if(ok[i].item <= avg) break;

					if(e == -1) e = ok[i].num;
					else
					{
						flag = false;
						break;
					}
				}
			}
			if(flag)
			{
				cout << ans << " ml. from cup #" << b  << " to cup #" << e << "." << endl;
			}
		}


	}     
	return 0;
}