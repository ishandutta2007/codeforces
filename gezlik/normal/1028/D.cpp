#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int INF=(1<<30)-1,mod=1000000007;

int n,ans;
priority_queue<int>q0;
priority_queue<int,vector<int>,greater<int> >q1;
multiset<int>s;

void into(){
  scanf("%d",&n);
  q0.push(-1);
  q1.push(INF);
  ans=1;
  for (int i=1;i<=n;++i){
	char opt[10];
	int x;
	scanf("%s%d",opt,&x);
	if (opt[1]=='D'){
	  if (x<q0.top()) {q0.push(x);continue;}
	  if (x>q1.top()) {q1.push(x);continue;}
	  s.insert(x);
	}else{
	  if (s.find(x)!=s.end()) {ans=ans*2%mod;s.erase(s.find(x));}
	  else if (q0.top()==x) q0.pop();
	    else if (q1.top()==x) q1.pop();
		  else {puts("0");exit(0);}
	  for (;!s.empty()&&*s.begin()<x;s.erase(s.begin())) q0.push(*s.begin());
	  for (;!s.empty()&&*--s.end()>x;s.erase(--s.end())) q1.push(*--s.end());
	}
  }
  //for (;!s.empty()&&*s.begin()<q0.top();s.erase(s.begin())) q0.push(*s.begin());
  //for (;!s.empty()&&*--s.end()>q1.top();s.erase(--s.end())) q1.push(*--s.end());
  int t=s.size()+1;
  ans=1LL*ans*t%mod;
  //if (ans==335947358) printf("%d\n",t);
  printf("%d\n",ans);
}

void work(){
}

void outo(){
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}