#include<cstdio>
#include<vector>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100000
int n,g[MAX],seen[MAX],next_seen;
vector<int> t;
bool ok(long long y,long long x){
  if(y*y>x)return false;
	return min(min(y*y,x)*y,x)*y>=x;
}
main(){
  for(int i=1;i<MAX;i++){
		++next_seen;
		int j=(int)sqrt(sqrt(i));
		while(min(MAX,min(MAX,j*j)*j)*j<i)++j;
//		cout<<j<<endl;
		while((long long)j*j<=i&&j<i){
			seen[g[j]]=next_seen;
		  ++j;
		}
		while(seen[g[i]]==next_seen)++g[i];
		if(g[i]!=g[i-1]){
		  t.push_back(i);
			t.push_back(i-1);
//						cout<<i<<" "<<g[i]<<endl;
    }
	}
  scanf("%d",&n);
	int ans=0;
	for(int i=0;i<n;i++){
	  long long tmp;
    scanf("%I64d",&tmp); 
    if(tmp<MAX)ans^=g[tmp];else{
      ++next_seen;
			for(int i=0;i<t.size();i++)if(ok(t[i],tmp))seen[g[t[i]]]=next_seen;
			long long r=sqrt(sqrt(tmp));
			while((r+1)*(r+1)*(r+1)*(r+1)<=tmp)++r;
			seen[g[r]]=next_seen;
			int pos=0;
			while(seen[pos]==next_seen)++pos;
			ans^=pos;
		}
	}
  puts(ans?"Furlo":"Rublo");
}