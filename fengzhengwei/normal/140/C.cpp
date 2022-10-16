#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int n,a[xx];
map<int,int>mp;
struct node{int val,id;bool operator<(const node&w)const{return val>w.val;};};
multiset<node>s;
struct no{int x,y,z;void clear(){if(x<y)swap(x,y);if(x<z)swap(x,z);if(y<z)swap(y,z);}};
vector<no>ans;
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),mp[a[i]]++;
	for(int i=1;i<=n;i++)if(mp[a[i]])s.insert((node){mp[a[i]],a[i]}),mp[a[i]]=0;
	while(s.size()>=3)
	{
		node a=*s.begin();
		s.erase(s.begin());
		node b=*s.begin();
		s.erase(s.begin());
		node c=*s.begin();
		s.erase(s.begin());
		ans.push_back((no){a.id,b.id,c.id});
		a.val--,b.val--,c.val--;
		if(a.val)s.insert(a);
		if(b.val)s.insert(b);
		if(c.val)s.insert(c);
	}
	cout<<ans.size()<<"\n";
	for(auto it:ans)
	{
		it.clear();
		cout<<it.x<<" "<<it.y<<" "<<it.z<<"\n";
	}
	return 0;
}