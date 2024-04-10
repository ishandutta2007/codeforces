#include<iostream>
#include<algorithm>
#include<vector>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;
int k,m,n;
vector <int> a,b;

int main()
{
    int i,j;
    cin >> n >> m >> k;
    a.clear();
    fr(i,1,m)
      if (1LL*i*i>m) break;
      else 
      {
         if (m%i==0)
         {
            if (i>=k) a.push_back(i);
            if (m/i>=k && m/i!=i) a.push_back(m/i);
         }
      }
    if (!a.empty()) 
    {
      sort(a.begin(),a.end());
      fr(i,0,a.size()-1)
      {
         b.push_back(-1);               
         fr(j,0,i-1)
           if (a[i]%a[j]==0) 
           {
              int x=a[i]/a[j];
              if (b[j]<0)
              {
                 b[i]=1; break;        
              }         
              if (b[j]^(x%2)) 
              {
                 b[i]=1; break;                
              }    
              b[i]=0; 
           }
      }
      i--;
    }
    if (!a.empty() && b[i]>=0 && (b[i]^(n%2==0))) cout << "Timur" << endl;
    else cout << "Marsel" << endl;
    //system("pause");
    return 0;
}