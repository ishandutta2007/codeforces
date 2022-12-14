#pragma optimize ("O3") 
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define getchar() (*SS++) 
#define MN 100000
char B[1<<26],*SS=B;
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
pair<int,int> b1[MN+5],b2[MN+5];long long Ans[MN+5];
int n,Q,a[MN+5],s[MN+5],size,block[MN+5],L=1,R=0,top1,top2,tail1,tail2,num[MN+5],ne[MN+5],la[MN+5],S[MN+5];
struct ques{int l,r,id;}q[MN+5];
bool cmp(const ques&a,const ques&b){return block[a.l]==block[b.l]?a.r<b.r:a.l<b.l;}
inline void Add(int x){if(!num[x]++) la[x]=0,ne[x]=ne[0],la[ne[x]]=x,ne[0]=x;}
inline void Del(int x){if(!--num[x]) ne[la[x]]=ne[x],la[ne[x]]=la[x];}
inline void Add(int x,int v){if(s[x]) Del(s[x]);s[x]+=v;if(s[x]) Add(s[x]);}
inline void Insert(int x,int v){if(top2>=tail2&&b2[top2].first==x) b2[top2].second+=v;else b2[++top2]=make_pair(x,v);}
int main()
{
	fread(B,1,1<<26,stdin);n=read();size=350;
	for(register int i=1;i<=n;++i) a[i]=read(),block[i]=(i-1)/size+1;
	Q=read();
	for(register int i=1;i<=Q;++i) q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+Q+1,cmp);
	for(register int i=1;i<=Q;++i)
	{
		while(L>q[i].l) Add(a[--L],1);
		while(R<q[i].r) Add(a[++R],1);
		while(L<q[i].l) Add(a[L++],-1);
		while(R>q[i].r) Add(a[R--],-1);
		long long res=0;top1=top2=0;tail1=tail2=1;pair<int,int> B;
		for(int j=ne[0];j;j=ne[j]) b1[++top1]=make_pair(j,num[j]);
		sort(b1+1,b1+top1+1);
		while(top1>=tail1||top2>=tail2)
		{
			if(top1>=tail1&&(top2<tail2||b1[tail1].first<b2[tail2].first)) B=b1[tail1++]; else B=b2[tail2++];
			res+=1LL*(B.second>>1)*B.first<<1;
			if(B.second>=2)Insert(B.first<<1,B.second>>1);
			if(B.second&1)
			{
				if(top1<tail1&&top2<tail2) break; 
				if(top1>=tail1&&(top2<tail2||b1[tail1].first<b2[tail2].first))
				{
					res+=B.first+b1[tail1].first;
					Insert(B.first+b1[tail1].first,1);
					if(!--b1[tail1].second) ++tail1;
				}
				else
				{
					res+=B.first+b2[tail2].first;
					Insert(B.first+b2[tail2].first,1);	
					if(!--b2[tail2].second) ++tail2;
				}
			} 
		}	
		Ans[q[i].id]=res;
	}
	for(register int i=1;i<=Q;++i) printf("%lld\n",Ans[i]);
	return 0;
}