#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int a;
const int xx=1e5+5;
char s[xx];
struct node{int xs,op;bool operator<(const node&w)const{return xs<w.xs;};}e[xx]; 
//0++a1a++ 
int L=1,R;
void gnum(int l,int r){L=l,R=r;}
char gc()
{
	if(L<=R)return s[L++];
	return EOF;
}
int read()
{
	char c;
	int w=1;
	while((c=gc())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=gc())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
signed main(){
//	freopen("a.in","r",stdin);
	cin>>a;
	scanf("%s",s+2);s[1]='+';
	int n=strlen(s+1),tt=0;
//	cout<<s+1<<"\n";
	for(int i=1;i<=n;i++)
	{
		int id=i;
		while(s[id]!='a')id++;
//		cerr<<i<<" "<<id<<"\n";
		int X=1;
		for(int j=i;j<=id;j++)
			if(s[j]=='*')gnum(i+1,j),X=read();
		tt++;
		if(s[i]=='-')X*=-1;e[tt].xs=X;//++ 
		if(id>=i+3&&s[id-1]=='+'&&s[id-2]=='+')e[tt].op=0,i=id;
		else id+=2,i=id,e[tt].op=1;
	}
	sort(e+1,e+tt+1);
	ll ans=0;
	for(int i=1;i<=tt;i++)
	{
		if(e[i].op==0)a++;
//		cout<<e[i].xs<<" "<<a<<"\n";
		ans+=1ll*e[i].xs*a;
		if(e[i].op==1)a++;
	}
	cout<<ans<<"\n";
	return 0;
}