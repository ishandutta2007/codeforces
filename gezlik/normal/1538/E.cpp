#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=50000;

int cq,cn;
map<string,int>mp;

bool Check(char a,char b,char c,char d){return a=='h'&&b=='a'&&c=='h'&&d=='a';}

struct thing{
  
  LL len,sum;
  char l[4],r[4];
  
  thing(){len=sum=0;l[0]=l[1]=l[2]=l[3]=r[0]=r[1]=r[2]=r[3]='c';}
  
  thing(string s){
	len=s.size();
	sum=0;
	for (int i=0;i+3<s.size();++i)
	  if (Check(s[i],s[i+1],s[i+2],s[i+3])) ++sum;
    if (len>=1) l[0]=s[0],r[0]=s[len-1];
    if (len>=2) l[1]=s[1],r[1]=s[len-2];
    if (len>=3) l[2]=s[2],r[2]=s[len-3];
    if (len>=4) l[3]=s[3],r[3]=s[len-4];
  }
  
}a[N+9];

thing Merge(thing a,thing b){
  thing res;
  res.len=a.len+b.len;
  res.sum=a.sum+b.sum;
  for (int i=0;i<4;++i) res.l[i]=a.l[i];
  if (a.len<4)
    for (int i=a.len;i<4;++i) res.l[i]=b.l[i-a.len];
  for (int i=0;i<4;++i) res.r[i]=b.r[i];
  if (b.len<4)
    for (int i=b.len;i<4;++i) res.r[i]=a.r[i-b.len];
  if (a.len>=1&&b.len>=3) res.sum+=Check(a.r[0],b.l[0],b.l[1],b.l[2]);
  if (a.len>=2&&b.len>=2) res.sum+=Check(a.r[1],a.r[0],b.l[0],b.l[1]);
  if (a.len>=3&&b.len>=1) res.sum+=Check(a.r[2],a.r[1],a.r[0],b.l[0]);
  return res;
}

void into(){
}

void Get_ans(){
  mp.clear();
  cn=0;
  cin>>cq;
  for (;cq--;){
	string s;
	cin>>s;
	if (!mp[s]) a[mp[s]=++cn]=thing();
	int k=mp[s];
	cin>>s;
	if (s==":="){
	  cin>>s;
	  a[k]=thing(s);
	}else{
	  string x,y;
	  cin>>x>>s>>y;
	  if (!mp[x]) a[mp[x]=++cn]=thing();
	  if (!mp[y]) a[mp[y]=++cn]=thing();
	  a[k]=Merge(a[mp[x]],a[mp[y]]);
	}
	if (!cq) cout<<a[k].sum<<endl;
  }
}

void work(){
  Get_ans();
}

void outo(){
}

int main(){
  int T=1;
  //scanf("%d",&T);
  cin>>T;
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}