#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
L n,m;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	L i,k;
	cin>>n>>m;
	for(i=1,k=1;i<=m;i++)
	  {
	   if((n+1)/(k/__gcd(k,i))<i)
	     break;
	   k=k/__gcd(k,i)*i;
	  }
	if(i>m && (n+1)%k==0)
	  printf("Yes\n");
	else
	  printf("No\n");
	return 0;
}