#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,ta,a[101010],p[2][101010],ST[4][404040],L[101010],R[101010],q,x[101010],y[101010],z[101010],jaw[101010];
pair<ll,ll> A[101010];
vector<ll> C[101010];
void upd(ll aa,ll bb,ll cc,ll ee)
{
	if(aa==bb)
	{
		ST[0][ee]=1;
		ST[1][ee]=1;
		ST[2][ee]=1;
		ST[3][ee]=1;
	}
	else
	{
		ll ce=(aa+bb)/2;
		if(cc<=ce)
			upd(aa,ce,cc,ee*2);
		else
			upd(ce+1,bb,cc,ee*2+1);

		if(ST[2][ee*2]==1)ST[0][ee]=ST[0][ee*2]+ST[0][ee*2+1];
		else ST[0][ee]=ST[0][ee*2];
		
		if(ST[2][ee*2+1]==1)ST[1][ee]=ST[1][ee*2]+ST[1][ee*2+1];
		else ST[1][ee]=ST[1][ee*2+1];
		
		ST[2][ee]=min(ST[2][ee*2],ST[2][ee*2+1]);
		
		ST[3][ee]=max(ST[1][ee*2]+ST[0][ee*2+1],max(ST[3][ee*2],ST[3][ee*2+1]));
	}
}
vector<ll> X;
void cari(ll aa,ll bb,ll cc,ll dd,ll ee)
{
	if(bb<cc|dd<aa)return ;
	else
	if(cc<=aa&&bb<=dd)
	{
		X.pb(ee);
	}
	else
	{
		ll ce=(aa+bb)/2;
		cari(aa,ce,cc,dd,ee*2);
		cari(ce+1,bb,cc,dd,ee*2+1);
	}
}
ll car(ll aa,ll bb)
{
	if(p[bb][aa]==aa)return aa;
	else
	{
		ll tem=car(p[bb][aa],bb);
		p[bb][aa]=tem;
		return tem;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		A[i]=mp(ta,i);
	}
	sort(A+1,A+1+n);
	reverse(A+1,A+1+n);
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		L[i]=1;
		R[i]=n;
		C[(1+n)/2].pb(i);
	}
	bool butuh=1;
	while(butuh)
	{
		butuh=0;
		// 0 kanan
		// 1 kiri
		memset(ST,0,sizeof(ST));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)p[0][i]=i;
		for(i=1;i<=n;i++)p[1][i]=i;
		for(i=1;i<=n;i++)
		{
			ll pos=A[i].se;
			a[pos]=1;
			if(a[pos+1]==1)
			{
				p[0][pos]=pos+1;
				p[1][pos+1]=pos;
			}
			if(a[pos-1]==1)
			{
				p[0][pos-1]=pos;
				p[1][pos]=pos-1;
			}
			upd(1,n,pos,1);
		//	cout<<i<<" "<<que(1,n,1,5,1,3)<<"\n";
		//	cout<<i<<" "<<que(1,n,2,5,1,3)<<"\n";
		//	cout<<i<<" "<<que(1,n,1,5,1,3)<<"\n";
		//	continue;
			while(!C[i].empty())
			{
				butuh=1;
				ll now=C[i].back();
				C[i].pop_back();
				ll kanX=car(x[now],0);
				ll kirY=car(y[now],1);
				ll hz=0;
				//cout<<i<<" "<<now<<" "<<x[now]<<" "<<y[now]<<" "<<kanX<<" "<<kirY<<"\n";
				//1
				if((a[x[now]]==1)&&(kanX<y[now]))
					hz=max(hz,kanX-x[now]+1);
				if((a[y[now]]==1)&&(kirY>x[now]))
					hz=max(hz,y[now]-kirY+1);
				if(kanX>=y[now]&&a[x[now]])
					hz=max(hz,y[now]-x[now]+1);
				else
				{
					X.clear();
					cari(1,n,kanX+1,kirY-1,1);
					ll ii,jj,temp=0,sz=X.size();
					for(ii=0;ii<sz;ii++)
					{
						hz=max(hz,ST[3][X[ii]]);
						temp=ST[1][X[ii]];
						for(jj=ii+1;jj<sz;jj++)
						{
							temp+=ST[0][X[jj]];
							hz=max(hz,temp);
							if(ST[2][X[jj]]==0)
								break;
						}
					}
				}
				//cout<<i<<" "<<x[now]<<" "<<y[now]<<" "<<kanX<<" "<<kirY<<" "<<now<<" "<<hz<<"\n";
				if(hz>=z[now])
				{
					//cout<<i<<"\n";
					jaw[now]=A[i].fi;
					R[now]=i-1;
				}
				else
					L[now]=i+1;
				if(L[now]<=R[now])
					C[(L[now]+R[now])/2].pb(now);
			}
		//	cout<<i<<" "<<A[i].fi<<" "<<A[i].se<<"\n";
		}
		if(!butuh)break;
	}
	for(i=1;i<=q;i++)cout<<jaw[i]<<"\n";
}