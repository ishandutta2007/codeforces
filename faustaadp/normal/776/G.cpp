#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll a[2010101],p[2010101],K,q,i,b[101010],j,n;
ll jaw[101010];
ll bts[101010];
ll x[101010];
ll d[22][2][2][2];
string ta,tb;
ll cek(ll aa)
{
	ll ii,H=0,tem=0;
	for(ii=0;ii<16;ii++)b[ii]=0;
	tem=aa;
	if(aa==0)
		b[0]=1;
	else
	{
		while(tem>0)
		{
		//	cout<<tem%16<<"_\n";
			b[tem%16]=1;
			tem/=16;
		}
	}
	for(ii=0;ii<16;ii++)H+=((1<<ii)*b[ii]);
	//cout<<H<<" "<<aa<<"\n";
	H=(H^aa);	
	//cout<<H<<" "<<aa<<"\n";
	return (H<aa);
}
ll con(string aa)
{
	ll ii,H=0,K=1;
	for(ii=aa.length()-1;ii>=0;ii--)
	{
		ll tom=0;
		if('0'<=aa[ii]&&aa[ii]<='9')
			tom=aa[ii]-'0';
		else
			tom=aa[ii]-'a'+10;
		H+=tom*K;
		K*=16;
	}
	//cout<<aa<<" "<<H<<"\n";
	return H;
}
ll cari(ll aa,ll bb,ll cc)
{
	ll tom=j/4,H=0;
	if(aa==tom)
	{
		ll tam=j%4;
		ll ii;
		for(ii=bb;ii<=min(cc,bts[aa]);ii++)
			if((ii&(1<<tam)))
				H++;
		return H;
	}
	else
		return max(0LL,(min(cc,bts[aa])-bb+1));
}
ll depe(ll aa,ll bb,ll cc,ll dd)
{
	if(aa==n)
	{
		return (cc*dd);
	}
	if(d[aa][bb][cc][dd]==-1)
	{
		ll tem=0,ii,za=j/4,zo=j%4;
		zo=(1<<zo);
		if((n-aa-1)==za)
		{
			//cout<<j<<"__\n";
		//	cout<<j<<" "<<aa<<"___"<<zo<<"\n";
			if(bb)
			{
				for(ii=0;ii<min(j+1,x[aa]);ii++)
					if((ii&zo))
					{
						if(ii==j)
							tem+=depe(aa+1,0,1,1);
						else
							tem+=depe(aa+1,0,cc,1);
					}
				for(ii=x[aa];ii<=min(j,x[aa]);ii++)
					if((ii&zo))
					{
						if(ii==j)
							tem+=depe(aa+1,1,1,1);
						else
							tem+=depe(aa+1,1,cc,1);
					}
			}
			else
			{
				for(ii=0;ii<=j;ii++)
					if((ii&zo))
					{
						if(ii==j)
							tem+=depe(aa+1,0,1,1);
						else
							tem+=depe(aa+1,0,cc,1);
					}
			}
		}
		else
		{
			if(bb)
			{
				for(ii=0;ii<min(j+1,x[aa]);ii++)
					{
						if(ii==j)
							tem+=depe(aa+1,0,1,dd);
						else
							tem+=depe(aa+1,0,cc,dd);
					}
				for(ii=x[aa];ii<=min(j,x[aa]);ii++)
					{
						if(ii==j)
							tem+=depe(aa+1,1,1,dd);
						else
							tem+=depe(aa+1,1,cc,dd);	
					}
			}
			else
			{
				for(ii=0;ii<=j;ii++)
					{
						if(ii==j)
							tem+=depe(aa+1,0,1,dd);
						else
							tem+=depe(aa+1,0,cc,dd);
					}
			}
		}
		//cout<<j<<" "<<aa<<" "<<bb<<" "<<cc<<" "<<tem<<"\n";
		d[aa][bb][cc][dd]=tem;
	}
	return d[aa][bb][cc][dd];
}
ll cak(string aa)
{
	ll ii,H=0;
	n=aa.length();
	for(ii=0;ii<n;ii++)
	{
		if('0'<=aa[ii]&&aa[ii]<='9')
			x[ii]=aa[ii]-'0';
		else
			x[ii]=aa[ii]-'a'+10;
	}
	for(j=0;j<16;j++)
	{
		memset(d,-1,sizeof(d));
		H+=depe(0,1,0,0);
	}
	return H;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	bts[0]=1;
	for(i=1;i<=100;i++)
		bts[i]=0;
	// for(i=1;i<=60;i++)
	// {
	// 	ll kel=i/4;
	// 	if(bts[kel]==7)bts[kel]=15;
	// 	if(bts[kel]==3)bts[kel]=7;
	// 	if(bts[kel]==1)bts[kel]=3;
	// 	if(bts[kel]==0)bts[kel]=1;
	// 	//if(i==2)
	// 	//	cout<<bts[0]<<" "<<bts[1]<<" "<<bts[2]<<" "<<bts[3]<<"\n";
	// 	for(j=0;j<16;j++)
	// 	{
	// 		ll ii,jj;
	// 		for(ii=0;ii<16;ii++)
	// 		{
	// 			ll hz=1;
	// 			for(jj=0;jj<16;jj++)
	// 			{
	// 				if(ii==jj)
	// 					hz*=cari(jj,j,j);
	// 				else
	// 				if(ii<jj)
	// 					hz*=cari(jj,0,j);
	// 				else
	// 					hz*=cari(jj,0,j-1);
	// 			}
	// 			jaw[i]+=hz;
	// 		}
	// 	// 	jaw[i]+=cari(3,j,j)*cari(2,0,j)*cari(1,0,j)*cari(0,0,j);
	// 	// //	if(i==5)cout<<j<<" "<<jaw[i]<<"_\n";
	// 	// 	jaw[i]+=cari(3,0,j-1)*cari(2,j,j)*cari(1,0,j)*cari(0,0,j);
	// 	// //	if(i==5)cout<<j<<" "<<jaw[i]<<"_\n";
	// 	// 	jaw[i]+=cari(3,0,j-1)*cari(2,0,j-1)*cari(1,j,j)*cari(0,0,j);
	// 	// //	if(i==5)cout<<j<<" "<<jaw[i]<<"_\n";
	// 	// 	jaw[i]+=cari(3,0,j-1)*cari(2,0,j-1)*cari(1,0,j-1)*cari(0,j,j);
	// 	// //	if(i==5)cout<<j<<" "<<jaw[i]<<"_\n";
	// 	}
	// }
	for(i=1;i<=60;i++)
	{
		if(i%4==3)
			jaw[(i+1)/4]=jaw[i];
	}
	// for(i=1;i<=15;i++)
	// 	cout<<i<<" "<<jaw[i]<<"\n";
	cin>>q;
	while(q--)
	{
		cin>>ta>>tb;
		cout<<cak(tb)-cak(ta)+cek(con(ta))<<"\n";
		//cout<<p[con(tb)+1]-p[con(ta)]<<"\n";
	}
}