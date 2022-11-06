#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll INF=1e18;
ll n,i,x[220],y[220],te,j,b[220][220],k,besar[40404],ta,tb,q;
vector<ll> gar[40404],isi[40404];
long double M[16][220][220],tempe[220],A[220],has;
ll cak(ll aa,ll bb,ll cc,ll dd)
{
	ll Xa=x[bb]-x[aa],Ya=y[bb]-y[aa];
	return ((Xa*dd)==(Ya*cc));
}
void cek(ll aa,ll bb)
{
	ll ii,jj,X=x[bb]-x[aa],Y=y[bb]-y[aa],GS;
	gar[te].pb(aa);
	for(ii=1;ii<=n;ii++)
		if(ii!=aa)
			if(cak(aa,ii,X,Y))
				gar[te].pb(ii);
	for(ii=0;ii<gar[te].size();ii++)
	{
		isi[gar[te][ii]].pb(te);
		besar[gar[te][ii]]++;
	//	cout<<te<<" "<<gar[te][ii]<<"\n";
	}
	GS=gar[te].size();
	for(ii=0;ii<GS;ii++)
		for(jj=0;jj<GS;jj++)
			b[gar[te][ii]][gar[te][jj]]=1;
}
void kal(ll aa)
{
	ll ii,jj;
	for(ii=1;ii<=n;ii++)tempe[ii]=0;
	for(ii=1;ii<=n;ii++)
		for(jj=1;jj<=n;jj++)
			tempe[jj]+=(A[ii]*M[aa][jj][ii]);
	for(ii=1;ii<=n;ii++)A[ii]=tempe[ii];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(!b[i][j])
			{
				te++;
				cek(i,j);
			}
	for(i=1;i<=n;i++)
	{
		long double K1=1.0/(long double)besar[i];
		for(j=0;j<besar[i];j++)
		{
			for(k=0;k<gar[isi[i][j]].size();k++)
			{
				long double K2=1.0/(long double)gar[isi[i][j]].size();
				K2*=K1;
				M[0][i][gar[isi[i][j]][k]]+=K2;
			}
		}
	}
	for(ll I=1;I<=15;I++)	
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					M[I][i][j]+=M[I-1][i][k]*M[I-1][k][j];
	cin>>q;
	while(q--)
	{
		cin>>ta>>tb;
		for(i=1;i<=n;i++)
			A[i]=0.0;
		A[ta]=1;
		//cout<<K3<<"\n";
		//cout<<"\n";
		//A[4]=0.5;	
		//tb--;
		//A[3]=1;
	//	A[1]=0.5;
	//	A[4]=0.5;
		tb--;
		for(i=0;i<16;i++)
			if(tb&(1<<i))
			{
				//cout<<i<<" ";
				kal(i);
			}
		//for(i=1;i<=n;i++)
		//	cout<<A[i]<<" ";
		//cout<<"\n";
		has=0;
		for(i=1;i<=te;i++)
		{
			long double hz=0,K3=1.0/(long double)gar[i].size();
	//		K3=1;
			for(j=0;j<gar[i].size();j++)
				hz+=A[gar[i][j]]*K3; 
			has=max(has,hz);
		}
		//has=A[ta];
		cout<<fixed<<setprecision(21)<<has<<"\n";
	}
	
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<fixed<<setprecision(2)<<M[0][i][j]<<" ";
		cout<<"\n";
	}*/
	
}