//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const int B=432;
int n,cnt[100111],a[100111],b[100111],tb[100111],ans[100111];
int bg[100111],bgsz,id[100111],ql[100111],qr[100111];
bool cmp(int x,int y)
{
	if(ql[x]/B!=ql[y]/B)return ql[x]/B<ql[y]/B;
	return qr[x]<qr[y];
}
priority_queue<int>pq;
int solve()
{
//	cout<<"solve:"<<endl;
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
	for(int i=1;i<=B*2;i++)tb[i]=b[i];
	for(int i=0;i<bgsz;i++)tb[cnt[bg[i]]]=b[cnt[bg[i]]];
	int ret=0,tmp=0;
	for(int i=1;i<=B;i++)
	{
		if(!b[i])continue;
		if(tmp&&tmp<=i)
		{
			ret+=tmp+i;
			b[tmp+i]++;
			b[i]--;
			tmp=0;
		}
		b[i<<1]+=b[i]>>1;
		if(b[i]&1)
		{
			ret+=i*(b[i]-1);
			tmp=i;
		}
		else
		{
			ret+=i*b[i];
		}
		b[i]=0;
	}
	if(tmp)pq.push(-tmp);
	for(int i=B+1;i<=B*2;i++)
	{
		if(b[i]<=0)continue;
		while(b[i]--)pq.push(-i);
	}
	for(int i=0;i<bgsz;i++)
	{
		int x=cnt[bg[i]];
		if(x==0||b[x]<=0)continue;
		while(b[x]--)pq.push(-x);
	}
	while(!pq.empty())
	{
		int x=-pq.top();pq.pop();
		if(pq.empty())break;
		int y=-pq.top();pq.pop();
		ret+=x+y;
		pq.push(-x-y);
	}
	for(int i=1;i<=B*2;i++)b[i]=tb[i];
	for(int i=0;i<bgsz;i++)b[cnt[bg[i]]]=tb[cnt[bg[i]]];
	return ret;
}
void add(int x)
{
	b[cnt[x]++]--;
	b[cnt[x]]++;
}
void del(int x)
{
	b[cnt[x]--]--;
	b[cnt[x]]++;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(cnt[i]>B)
		{
			bg[bgsz++]=i;
		}
	}
	memset(cnt,0,sizeof(cnt));
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		getii(ql[i],qr[i]);
		if(ql[i]>qr[i])swap(ql[i],qr[i]);
		id[i]=i;
	}
	sort(id+1,id+q+1,cmp);
	int L=1,R=0;
	for(int i=1;i<=q;i++)
	{
		int x=id[i],l=ql[x],r=qr[x];
//		cout<<"query:"<<x<<" "<<l<<" "<<r<<endl;
		while(R<r)add(a[++R]);
		while(R>r)del(a[R--]);
		while(L<l)del(a[L++]);
		while(L>l)add(a[--L]);
		ans[x]=solve();
	}
	for(int i=1;i<=q;i++)putsi(ans[i]);
	return 0;
}