#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
string s;
ll n,m,i,j,x,y,i1,i2,i3,i4,c[255],hv,dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},hs;
char a[1010][1010];
void rmt(ll aa,ll bb,ll cc)
{
	if(a[aa][bb]=='E')
		hv=1;
	if(cc==s.length()-1)
		return ;
	if(aa<=0||aa>n||bb<=0||bb>m)
		return ;
	if(a[aa][bb]=='#')
		return ;
	rmt(aa+dx[c[s[cc+1]]],bb+dy[c[s[cc+1]]],cc+1);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='S')
			{
				x=i;
				y=j;
			}
		}
	}
	cin>>s;
	for(i1=1;i1<=4;i1++)
		for(i2=1;i2<=4;i2++)
			for(i3=1;i3<=4;i3++)
				for(i4=1;i4<=4;i4++)
				{
					if(i1==i2||i1==i3||i1==i4||i2==i3||i2==i4||i3==i4)
						continue;
					c['0']=i1;
					c['1']=i2;
					c['2']=i3;
					c['3']=i4;
					hv=0;
					rmt(x,y,-1);
					hs+=hv;
				}
	cout<<hs<<"\n";
}