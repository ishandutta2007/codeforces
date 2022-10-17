#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define dd double
#define int ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
//	else assert(0);
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
// 
//4e3 
//int f[xx][xx],lin[xx],B[xx];
//void upd(int *A,int *B,int n){for(int i=1;i<=n;i++)A[i]=max(A[i],B[i]);}
//void ad(int *A,int *B,int n){/*cout<<n<<"%^%^\n";*/for(int i=1;i<=n;i++)A[i]+=B[i];}
//void up(int *A,int n,int l)
//{
//	multiset<int>s;
//	//n-l~n+l 
//	for(int i=1;i<=n;i++)B[i]=A[i];
//	for(int i=1;i<=min(n,l+1);i++)s.insert(A[i]);
//	for(int i=1;i<=n;i++)
//	{
////	cout<<n<<" "<<l<<' '<<i<<" "<<A[i]<<" "<<i+l+1<<" "<<(s.find(1)==s.end())<<" "<<s.size()<<"%%\n";
//		if(i-l-1>=1)s.erase(s.find(B[i-l-1]));
////	cout<<n<<" "<<l<<' '<<i<<" "<<A[i]<<" "<<i+l+1<<" "<<(s.find(1)==s.end())<<" "<<s.size()<<"%%\n";
//		assert(s.size());
//		A[i]=*--s.end();
//		if(i+l+1<=n)s.insert(A[i+l+1]);
//	}
//}
const int xx=2e5+5;
int n,m;
struct nod{int next,to,v;}e[xx<<1];//
int cnt,h[xx];
void add(int x,int y,int z){cnt++,e[cnt]={h[x],y,z},h[x]=cnt;}
struct pr{int x,y;bool operator<(const pr&w)const{return x==w.x?y>w.y:x<w.x;};};
vector<pr>v[xx];//
struct sval
{
	int id;
	mutable int v;
	bool operator<(const sval&w)const{return id<w.id;}//
};
#define S multiset<sval>
void in(S &a,sval t)
{
	auto it=a.find(t);//
	if(it!=a.end())it->v+=t.v;
	else a.insert(t);
}
// 
auto pre(S &a,int id)
{
	auto it=a.upper_bound({id});//
	if(it==a.begin())return a.end();
//	{-1,-1};
	return --it;
}
auto nex(S &a,int id)
{
	auto it=a.lower_bound({id});//
	if(it==a.end())return a.end();
//	{-1,-1};
	return it;
}
struct Pr
{
	S Sz,Sf,D;// 
	//iddltv>0v<0 
	// 
	int tag;//
	int size(){return Sz.size()+Sf.size();}
}E[xx];//
//dlt 
auto find(Pr&A,int id,int op)
{
	if(op==0)//pre 
		return pre(A.Sf,id-A.tag); 
	return nex(A.Sz,id+A.tag); //
}
//-dlt+dlt 
sval operator+(const sval&a,const int &b){return {a.id+b,a.v};}//
void Ex(Pr&A,sval b,int op)
{
//	cout<<b.id<<" "<<op<<"@@@@\n";
	if(op>0)
	{
		auto it=find(A,b.id,0);
		if(it!=A.Sf.end())A.D.insert({b.id+A.tag-it->id,b.id+A.tag});//
	}
	else 
	{
		auto it=find(A,b.id,1);
		if(it!=A.Sz.end())A.D.insert({it->id-(b.id-A.tag),(b.id-A.tag)});//
	}
}
void In(Pr&A,sval b)// 
{
	if(!b.v)return;// 
	if(b.v>0)
	{
		in(A.Sz,b+A.tag);//
		auto it=find(A,b.id,0);
		if(it!=A.Sf.end())A.D.insert({b.id+A.tag-it->id,b.id+A.tag});//
		//tagclcltagtag 
	}
	else 
	{
		in(A.Sf,b+(-A.tag));
		auto it=find(A,b.id,1);
		if(it!=A.Sz.end())A.D.insert({it->id-(b.id-A.tag),(b.id-A.tag)});//
		//check 
	}
}
//clear 
void merge(Pr&A,Pr&B)
{
	if(A.size()<B.size())swap(A,B);//stlswap 
	for(auto it:B.Sz)In(A,it+(-B.tag)),assert(it.v>0);
	for(auto it:B.Sf)In(A,it+B.tag),assert(it.v<0);//
	B.Sz.clear(),B.Sf.clear(),B.D.clear(),B.tag=0;
}
//void merge(S&a,S&b)
//{
//	if(a.size()>b.size())swap(a,b);
//	for(auto it:v)a.insert(it);
//	b.clear();
//}
//multiset 
int gone(Pr&a,int b)
{
	int ans=0;
	if(a.Sz.find({b+a.tag})!=a.Sz.end())ans+=a.Sz.find({b+a.tag})->v;
	if(a.Sf.find({b-a.tag})!=a.Sf.end())ans+=a.Sf.find({b-a.tag})->v;
	return ans;
}
void print(Pr&A,string B)
{
return;
	cout<<B<<"\n";
	cout<<"Tag="<<A.tag<<"\n";
	for(auto it:A.Sz)
		cout<<it.id-A.tag<<" "<<it.v<<"\n";
	for(auto it:A.Sf)
		cout<<it.id+A.tag<<" "<<it.v<<"\n";
	puts("Out the print");
	puts("");
}
map<int,int>mp;
void anout(Pr&A,string B)
{
return;
	cout<<B<<"\n";
	cout<<"Tag="<<A.tag<<"\n";
	mp.clear();
	for(auto it:A.Sz)
		mp[it.id-A.tag]+=it.v;
	for(auto it:A.Sf)
		mp[it.id+A.tag]+=it.v;
//		cout<<it.id+A.tag<<" "<<it.v<<"\n";
//	for(auto it:mp)cout<<it.first<<"%%\n";
	for(int i=-100;i<=100;i++)mp[i]+=mp[i-1];
	for(int i=1;i<=40;i++)cout<<mp[i]<<" ";
	puts("");
//	puts("Out the print");
//	puts("");
}
void move(Pr&A,int bs)
{
//	cout<<bs<<"%%%%%%\n";
	int cr=0;//
	
	print(A,"inside move out one");
//	cout<<"BS= "<<bs<<"\n";
//	if(bs==15&&A.tag==17)
//	{
//		cr=1;
//		anout(A,"inside move out");
//	}
	while(A.D.size()&&(bs+A.tag)*2>=(A.D.begin()->id))
	{
		int ndis=(A.D.begin()->id);
		int pos=(A.D.begin()->v);
		A.D.erase(A.D.begin());//
//		cout<<pos<<"&*&*&*&\n";
		// 
	if(bs==15&&A.tag==17)
	{
//		cr=1;
		anout(A,"inside move out one");
	}
		if(A.Sz.find({pos})!=A.Sz.end())//
		{
//		cout<<pos<<" "<<A.Sz.find({pos})->v<<"%%%%\n";
		// 
		// 
			auto it=find(A,pos-A.tag,0);
			if(it!=A.Sf.end())//
			{
//		if(cr)cout<<pos<<" "<<it->id+A.tag<<" "<<pos-A.tag-A.tag<<"%%\n";
//				if(pos-it->id<=(bs+A.tag)*2)//
				if(pos-it->id==ndis)//
				{
					int v1=it->v,v2=A.Sz.find({pos})->v;
					int nid=pos,tid=it->id;
					A.Sf.erase(it);
					assert(A.Sz.count({pos})==1);
					A.Sz.erase(A.Sz.find({pos}));
					v1+=v2;
					if(v1>0)In(A,{nid-A.tag,v1});
					if(v1<0)In(A,{tid+A.tag,v1});
					if(v1==0)
					{
						it=find(A,pos-A.tag,0);
						if(it!=A.Sf.end())Ex(A,{it->id+A.tag,v1},-1);
						// 
					}
				}
			}
		}
//	if(bs==15&&A.tag==17)
//	{
////		cr=1;
//		++cr;
//		anout(A,"inside move out");
//		if(cr==3)exit(0);
//	}
//		if(pos==5)
//		{
//			
//	if(bs==1&&A.tag==2)
//	{
//		cr=1;
//		print(A,"inside 5 out");
//	}
//	
//		}
//		if(cr)cout<<pos<<" "<<(A.Sf.find({pos})==A.Sf.end())<<"^^^^\n";
		if(A.Sf.find({pos})!=A.Sf.end())//
		{
			auto it=find(A,pos+A.tag,1);//
			if(it!=A.Sz.end())
			{
//		if(cr)cout<<pos<<" "<<it->id-A.tag<<" "<<"%%\n";
//				if(it->id-pos<=(bs+A.tag)*2)
				if(it->id-pos==ndis)
				{
					int v1=it->v,v2=A.Sf.find({pos})->v;//
					int nid=it->id,tid=pos;
					assert(A.Sf.count({pos})==1);
					A.Sf.erase(A.Sf.find({pos}));
					A.Sz.erase(it);
					v1+=v2;
					if(v1>0)In(A,{nid-A.tag,v1});
					if(v1<0)In(A,{tid+A.tag,v1});
					if(v1==0)
					{
						it=find(A,pos+A.tag,1);
						if(it!=A.Sz.end())Ex(A,{it->id-A.tag,v1},1);
						// 
					}
				}
			}
		}
		
//		A.D.insert({b.id+A.tag-it.id,b.id+A.tag});
	}
	
	print(A,"inside move out two");
	
	
	A.tag+=bs;//
	
	print(A,"inside move out three");
	
}
void dfs(int x,int y,int z)//
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x,e[i].v);//
		merge(E[x],E[e[i].to]);//
//		,ad(f[x],f[e[i].to],4e3);
	}
//	cout<<x<<" ";
	anout(E[x],"Print x up");
//	cout<<x<<" ";
//	print(E[x],"Print x up");
	vector<pr>V;////
	sort(v[x].begin(),v[x].end());//
	int ls=-1;//
	for(auto it:v[x])
	{
		if(it.x==ls)continue;//
		ls=it.x;//
		int d1=gone(E[x],it.x),d2=gone(E[x],it.x+1);//
//		cout<<d1<<" "<<d2<<" "<<it.x<<"&&&&&&&&&&&&&&&&&\n";
		if(0>=-d1&&0>=d2)V.push_back({it.x,it.y});
		else 
		{
			if(-d1>=d2)
			{
				if(-d1<it.y)
					V.push_back({it.x,it.y-(-d1)});
			}
			else 
			{
				if(d2<it.y)
					V.push_back({it.x,it.y-(d2)});
			}
		}
	}
	
//	puts("$#####");
	move(E[x],1);//
	
	
//	cout<<x<<"/ ";
//	print(E[x],"Print x one");
	
//	cout<<x<<" ";
	anout(E[x],"Print x one");
	for(auto it:V)
		In(E[x],{it.x,it.y}),
		In(E[x],{it.x+1,-it.y});
		//
	
//	cout<<x<<" ";
//	print(E[x],"Print x adcf");
	
//	cout<<x<<" ";
	anout(E[x],"Print x adcf");
	
	move(E[x],z-1);
	
	
//	cout<<x<<" ";
//	print(E[x],"Print x last");
//	cout<<x<<" ";
	anout(E[x],"Print x last");
	
//	cout<<z<<"$$\n";
//	if(x==5)exit(0);
//	for(int i=1;i<=4e3;i++)lin[i]=0;
//	for(auto it:v[x])
//		lin[it.x]=max(lin[it.x],f[x][it.x]+it.y);
//	up(f[x],4e3,1);
//	upd(f[x],lin,4e3);
//	up(f[x],4e3,z-1);
//	cout<<x<<" "<<y<<" "<<z<<"%%\n";
	
}
//#include<windows.h>
signed main(){
//	MessageBox(NULL,("a"),("b"),MB_OK|MB_ICONINFORMATION);
//	freopen("a.in","r",stdin);
	n=read();
//	if(n>1000)exit(0);
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read()*2;//
		add(a,b,c),add(b,a,c);
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read()*2,b=read(),c=read();//
		v[c].push_back({a,b});
	}
	dfs(1,0,1);
	int ans=0;
	S t;
	move(E[1],0);
	for(auto it:E[1].Sz)t.insert(it+(-E[1].tag));
	for(auto it:E[1].Sf)t.insert(it+E[1].tag);
	int res=0;
	// 
	for(auto it:t)
	{
		res+=it.v,ans=max(ans,res);
//		cout<<it.id<<" "<<res<<"$\n";
	}
//	for(int i=1;i<=4e3;i++)ans=max(ans,f[1][i]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}
/*

5
1 4 6
5 4 4
5 3 5
2 4 1
4
17 3 3
5 3 2
17 1 5
5 3 4

7
7 3 5
4 7 2
5 7 3
3 2 3
5 6 10
1 5 8
5
11 5 5
19 4 3
2 4 5
9 3 5
2 3 1

9
6 1 4
3 5 7
5 4 2
3 6 1
9 8 4
3 7 1
2 6 5
3 8 7
8
4 4 8
17 3 8
10 3 5
14 2 5
20 1 3
19 5 9
9 4 7
14 2 8

7
5 1 5
5 3 3
6 4 9
4 2 9
3 7 2
3 2 3
5
19 1 2
17 2 3
9 2 3
5 4 2
10 1 3
*/