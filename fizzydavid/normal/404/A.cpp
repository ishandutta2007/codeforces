#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
char a[310][310];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(i+j-1==n||i==j)
            {
                if(a[i][j]!=a[1][1])
                {
                    cout<<"NO";return 0;
                }
            }
            else 
            {
                if(a[i][j]!=a[1][2])
                {
                    cout<<"NO";return 0;
                }
            }
        }
    }
    if(a[1][1]!=a[1][2])cout<<"YES";else cout<<"NO";
 	return 0;
}