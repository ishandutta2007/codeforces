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
int x,y;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>x>>y;
	if(!y)
	  printf("No");
	else if(x<y-1)
	  printf("No");
	else if(y==1 && x)
	  printf("No");
	else
	  if((x-y+1)&1)
	    printf("No");
	  else
	    printf("Yes");
	return 0;
}