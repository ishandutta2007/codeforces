#include <cstdlib>    
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
ifstream fin("ab.txt");
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
template <class T> void quicksort(vector<T> &S,int a,int b) // 
{
     int x = a;
	 int y = b;
	 T mid = S[(a+b)>>1];
     while (x <= y)
     {
           while (S[x] < mid) x++;
           while (S[y] > mid) y--;
           if (x <= y)
           {
              swap(S[x], S[y]);
              x++;
              y--;
           }
     }
     if (x < b) quicksort(S, x, b);
     if (y > a) quicksort(S, a, y);
}
class dra
{
public:
	int s,b;
	bool operator < (dra& d)
	{
		return s < d.s;
	}
	bool operator > (dra& d)
	{
		return s > d.s;
	}
};
vector<dra> vd;
int main()
{
	int s,n;
	cin >> s >> n;
	vd.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> vd[i].s >> vd[i].b;
	}
	quicksort(vd,0,n-1);
	string str = "YES";
	for(int i = 0; i < n; i++)
	{
		if(s > vd[i].s)
		{
			s += vd[i].b;
		}
		else
		{
			str = "NO";
			break;
		}
	}
	cout << str << endl;
}