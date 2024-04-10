//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const ll mod=10000000000000061ll;
struct info
{
	ll hs;//false if hs==0
	int has;//bitmask of char
	int md;//modify info
	info(){hs=has=md=0;}
	void out(){cout<<hs<<" "<<has<<" "<<(md>>8)<<","<<char(md&255)<<endl;}
};
ll ans[100111][26];
info a[18][100111],a0[18][100111],a1[18][100111];//a0 a1 do not include mid modify
#define check(x,y) (a[x][y].hs>0)
info newinfo(char c)
{
	info ret;
	ret.hs=c-'a'+1;
	ret.has=1<<(c-'a');
	return ret;
}
info merge(const info &L,const char &c,const info &R)
{
//	cerr<<"merge:"<<L.hs<<","<<c<<","<<R.hs<<endl;
	info ret;
	if(!L.hs||!R.hs||L.hs!=R.hs)return ret;
	if((L.has>>(c-'a'))&1)return ret;
	if((R.has>>(c-'a'))&1)return ret;
	ret.hs=(L.hs*30+c-'a'+1)%mod;
	ret.has=L.has|(1<<(c-'a'));
	return ret;
}
int n;
char s[100111];
ll w[20];
void update(int msk,int k)
{
	ans[msk>>8][(msk&255)-'a']+=w[k];
}
void updatemsk(int x,int msk,int k)
{
	for(int i=0;i<26;i++)if((msk>>i)&1)update(x<<8|(i+'a'),k);
}
ll pe[100111];
int main()
{
	for(int k=0;k<20;k++)w[k]=1ll*((1<<(k+1))-1)*((1<<(k+1))-1);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)a[0][i]=newinfo(s[i]);
	for(int k=1;k<18;k++)
	{
		int l=(1<<k);
		for(int i=1;i<=n-(l*2-1)+1;i++)
		{
//			cerr<<"k="<<k<<" i="<<i<<endl;
			bool cl=check(k-1,i);
			bool cr=check(k-1,i+l);
			if(!cl&&!cr)continue;
			info &cur=a[k][i];
			int ls=i,rs=i+l;
			char &cmid=s[i+l-1];
			#define lmid s[ls+l/2-1]
			#define rmid s[rs+l/2-1]
			#define L a[k-1][ls]
			#define R a[k-1][rs]
			if(cl&&cr)
			{
				if(L.hs==R.hs)
				{
					cur=merge(L,cmid,R);
//					cerr<<"update:"<<k<<" "<<i<<endl;
					if(cur.hs)
					{
						pe[i]+=w[k];pe[i+l-1]-=w[k];
						pe[i+l]+=w[k];pe[i+l*2-1]-=w[k];
					}
					updatemsk(i+l-1,~(L.has|R.has),k);
				}
				else
				{
					if(k==1)
					{
						a0[k][i]=merge(R,cmid,R);a0[k][i].md=ls<<8|rmid;
						a1[k][i]=merge(L,cmid,L);a1[k][i].md=rs<<8|lmid;
					}
					else
					{
						a0[k][i]=merge(merge(a[k-2][ls],rmid,a[k-2][ls+l/2]),cmid,R);a0[k][i].md=(ls+l/2-1)<<8|rmid;
						a1[k][i]=merge(L,cmid,merge(a[k-2][rs],lmid,a[k-2][rs+l/2]));a1[k][i].md=(rs+l/2-1)<<8|lmid;
					}
				}
				continue;
			}
			if(cr)swap(ls,rs);
			if(lmid!=rmid)
			{
				a0[k][i]=merge(L,cmid,merge(a[k-2][rs],lmid,a[k-2][rs+l/2]));
				a0[k][i].md=(rs+l/2-1)<<8|lmid;
			}
			else
			{
				a0[k][i]=merge(L,cmid,a0[k-1][rs]);a0[k][i].md=a0[k-1][rs].md;
				a1[k][i]=merge(L,cmid,a1[k-1][rs]);a1[k][i].md=a1[k-1][rs].md;
			}
		}
	}
	for(int i=1;i<=n;i++)pe[i]+=pe[i-1];
	for(int k=1;k<18;k++)for(int i=1;i<=n;i++)
	{
		if(a0[k][i].hs)update(a0[k][i].md,k);//,a0[k][i].out();
		if(a1[k][i].hs)update(a1[k][i].md,k);//,a1[k][i].out();
	}
	ll mx=0,sum=0;
	for(int i=1;i<=n;i++)sum+=ans[i][s[i]-'a'];
//	cout<<"sum="<<sum+n<<endl;
	for(int i=1;i<=n;i++)
	{
		ll cur=sum-ans[i][s[i]-'a'];
		for(int j=0;j<26;j++)mx=max(mx,cur+ans[i][j]-pe[i]*('a'+j!=s[i]));
	}
	cout<<mx+n<<endl;
	return 0;
}