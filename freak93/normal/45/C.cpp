#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#define x first
#define y second

using namespace std;

int a[2200000],i,n,t1,t2,k;
string aux;
multiset<int>::iterator x,y;
pair<int,int> auxt,ans[2200000];

int mod(int a)
{
	if(a<0)
		return -a;
	return a;
}

struct fcomp
{
	bool operator()(pair<int,int> x,pair<int,int> y)
	{
		if(mod(a[x.x]-a[x.y])!=mod(a[y.x]-a[y.y]))
			return mod(a[x.x]-a[x.y])<mod(a[y.x]-a[y.y]);
		if(x.x!=y.x)
			return x.x<y.x;
		return x.y<y.y;
	}
};

multiset<int> S;
multiset<pair<int,int>, fcomp> C;

int main()
{
	cin>>n;cin.get();
	cin>>aux;
	for(i=1;i<=n;++i)
		cin>>a[i],S.insert(i);
	for(i=0;i<n;++i)
		if(aux[i]=='B')
			++t1;
		else
			++t2;
    for(i=n-1;i>0;--i)
		if(aux[i]!=aux[i-1])
			C.insert(make_pair(i,i+1));
	while(C.size()>0)
	{
		auxt=*C.begin();
		x=S.find(auxt.x);
		y=S.find(auxt.y);
		C.erase(auxt);
		if(x==S.end()||y==S.end())
			continue;
		ans[++k]=make_pair(*x,*y);
		if(x!=S.begin())
		{
			--x;
			++y;
			if(y!=S.end()&&aux[*x-1]!=aux[*y-1])
				C.insert(make_pair(*x,*y));
			++x;
		}
		S.erase(auxt.x),S.erase(auxt.y);
	}
	cout<<k<<"\n";
	for(i=1;i<=k;++i)
    	cout<<ans[i].x<<" "<<ans[i].y<<"\n";
}