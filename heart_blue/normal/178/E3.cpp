#include<bits/stdc++.h>
using namespace std;
const int MAX=2009;
const double pi=3.14159265358979323;
bool s[MAX][MAX];
long long a,b,c,d,n,m,x,y;
void dfs(int i,int j)
{
    s[i][j]=0,m++;
    if(i>a || (i==a && j>b) ) a=i,b=j;
    if(i<c || (i==c && j<d) ) c=i,d=j;
    if(i+1<n && s[i+1][j] ) dfs(i+1,j);
    if(j+1<n && s[i][j+1] ) dfs(i,j+1);
    if(j && s[i][j-1] ) dfs(i,j-1);
    if(i && s[i-1][j] ) dfs(i-1,j);
}
int main()
{	
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>s[i][j];   
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
			if(s[i][j])
			{
    	        m=0,a=-1,b=20000,c=20000,d=-1;
    	        dfs(i,j);
	            double e=(a-c)*(a-c)+(b-d)*(b-d);
				double m1=e/2.0;
				double m2=pi*e/4;
				if (m<150) continue;
				if (m>m1*1.1) x++;
				else y++;
	        }
	cout<<x<<" "<<y;
}