#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=1e5+5;
deque<int>s[xx];
int a[xx],B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}e[xx];
int t[xx],last[xx],maxx[xx],is[xx],res[xx],ans,vis;
bool check(deque<int>&Q)
{
	if(!Q.size())return 0;
	if(Q.size()==1)return 1;
//	cout<<*--Q.end()<<" "<<*Q.begin()<<"\n";
	if(maxx[*--Q.end()]<=*Q.begin())return 1;
	return 0;
}
void addr(int x)
{
	vis-=check(s[a[x]]);
	s[a[x]].push_back(x);
	vis+=check(s[a[x]]);
	if(s[a[x]].size()==1)ans++;
}
void addl(int x)
{
	vis-=check(s[a[x]]);
	s[a[x]].push_front(x);
	vis+=check(s[a[x]]);
	if(s[a[x]].size()==1)ans++;
}
void erasel(int x)
{
	vis-=check(s[a[x]]);
	s[a[x]].pop_front();
	vis+=check(s[a[x]]);
	if(s[a[x]].size()==0)ans--;
//	cout<<vis<<" sss "<<a[x]<<"\n";
}
void eraser(int x)
{
	vis-=check(s[a[x]]);
	s[a[x]].pop_back();
	vis+=check(s[a[x]]);
	if(s[a[x]].size()==0)ans--;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),last[i]=maxx[i]=is[a[i]]?is[a[i]]:i,is[a[i]]=i;
	for(int i=1;i<=n;i++)if(i-last[i]==last[i]-last[last[i]])maxx[i]=maxx[last[i]];
	int q=read();
	B=sqrt(q);
	for(int i=1;i<=q;i++)e[i].l=read(),e[i].r=read(),e[i].id=i;
//	for(int i=1;i<=n;i++)cout<<i<<" "<<maxx[i]<<"\n";
	sort(e+1,e+q+1);
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(r<e[i].r)addr(++r);
		while(l>e[i].l)addl(--l);
		while(r>e[i].r)eraser(r--);
		while(l<e[i].l)erasel(l++);
		res[e[i].id]=ans+(vis==0);
//		cout<<ans<<" "<<vis<<"sss\n";
	}
	for(int i=1;i<=q;i++)cout<<res[i]<<"\n";
	return 0;
}