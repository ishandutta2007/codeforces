#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,N,i,a[1010],d[1010],h[1010][1010],j,te,x[1010];
pair<ll,ll> A[1010];
ll cek(ll aa,ll bb)
{
	ll ii;
	for(ii=aa;ii<=bb;ii++)
		if(A[aa].se!=A[ii].se)return 0;
	return 1;
}
void pasang(ll aa,ll bb,ll cc)
{
	h[aa][bb]=cc;
	h[n-aa+1][bb]=cc;
	h[aa][n-bb+1]=cc;
	h[n-aa+1][n-bb+1]=cc;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	N=n*n;
	for(i=1;i<=N;i++)cin>>a[i];
	for(i=1;i<=N;i++)d[a[i]]++;
	ll F[5];
	F[0]=0;
	F[2]=1;
	F[3]=2;
	F[1]=3;
	for(i=1;i<=N;i++)
	{
		x[a[i]]++;
		if(x[a[i]]>(d[a[i]]%4))A[i]=mp(0,a[i]);
		else A[i]=mp(F[d[a[i]]%4],a[i]);
	}
	sort(A+1,A+1+N);
	//for(i=1;i<=N;i++)cout<<i<<" "<<A[i].fi<<" "<<A[i].se<<"\n";
	if(n%2==0)
	{
		for(i=1;i<=N;i+=4)
		{
			if(!cek(i,i+3))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		te=1;
		for(i=1;i<=n/2;i++)
			for(j=1;j<=n/2;j++)
			{
				pasang(i,j,A[te].se);
				te+=4;
			}
		cout<<"YES\n";
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(j<n)cout<<h[i][j]<<" ";
				else cout<<h[i][j]<<"\n";
	}
	else
	{
		ll NN=N-n-n+1;
		for(i=1;i<=NN;i+=4)
		{
			if(!cek(i,i+3))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		for(i=NN+1;i<N;i+=2)
		{
			if(!cek(i,i+1))
			{
				cout<<"NO\n";
				return 0;
			}
		}
		te=1;
		for(i=1;i<=n/2;i++)
			for(j=1;j<=n/2;j++)
			{
				pasang(i,j,A[te].se);
				te+=4;
			}
		for(i=1;i<=n/2;i++)
		{
			pasang(n/2+1,i,A[te].se);
			te+=2;
		}
		for(i=1;i<=n/2;i++)
		{
			pasang(i,n/2+1,A[te].se);
			te+=2;
		}
		h[n/2+1][n/2+1]=A[N].se;
		cout<<"YES\n";
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(j<n)cout<<h[i][j]<<" ";
				else cout<<h[i][j]<<"\n";
	}
}