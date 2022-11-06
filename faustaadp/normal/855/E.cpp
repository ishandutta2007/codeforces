#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,ta,tb,tc,has,d[11][1030][65][2];
ll depe(ll bs,ll bm,ll pan,ll lz)
{
	if(pan==0)
	{
		if(bm==0)
			return 1;
		else
			return 0;
	}
	if(d[bs][bm][pan][lz]!=-1)
		return d[bs][bm][pan][lz];
	ll ret=0;
	if(lz==0)
	{
		ll ii;
		for(ii=1;ii<bs;ii++)
		{
			ll tem=bm^(1<<ii);
			ret+=depe(bs,tem,pan-1,1);
		}
	}
	else
	{
		ll ii;
		for(ii=0;ii<bs;ii++)
		{
			ll tem=bm^(1<<ii);
			ret+=depe(bs,tem,pan-1,1);
		}
	}
	//cout<<bs<<" "<<bm<<" "<<pan<<" "<<lz<<" "<<ret<<"\n";
	return d[bs][bm][pan][lz]=ret;
}
string con(ll aa,ll bb)
{
	string z="";
	while(bb>0)
	{
		//cout<<bb<<"\n";
		z=char((bb%aa)+'0')+z;
		bb/=aa;
	}
	return z;
}
ll cek(ll aa,ll bb)
{
	if(bb==0)
		return 0;
	string s=con(aa,bb);
	ll sz=s.length(),ii,H=0,msk=0,jj;
	for(ii=1;ii<sz;ii++)
	{
	//	cout<<aa<<"_ "<<ii<<" "<<depe(aa,0,ii,0)<<"___\n";	
		H+=depe(aa,0,ii,0);
	}
	//cout<<H<<"^\n";
	for(ii=0;ii<sz;ii++)
	{
		ll tom=s[ii]-'0';
		for(jj=0;jj<tom;jj++)
		{
			if(ii==0&&jj==0)continue;
			msk^=(1<<jj);
	//		cout<<ii<<" "<<jj<<" "<<depe(aa,msk,sz-ii-1,1)<<"_\n";
			H+=depe(aa,msk,sz-ii-1,1);
			msk^=(1<<jj);
		}
		msk^=(1<<tom);
	}
	//cout<<aa<<" "<<bb<<" "<<H<<"\n";
	return H;
//	cout<<s<<"\n";
	//return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(d,-1,sizeof(d));
	cin>>t;
	while(t--)
	{
		cin>>ta>>tb>>tc;
		has=cek(ta,tc+1)-cek(ta,tb);
		cout<<has<<"\n";
	}
}