#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int c[1100000];
long long gcd(long long a,long long b){
	while(a){
		b%=a;swap(a,b);
	}
	return b;
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
vector<pair<int,int> > v;
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	for(int i=2;i<=b;i++){
		if(b%i)continue;
		int e=0;
		while(b%i==0){
			e++;
			b/=i;
		}
		v.push_back(make_pair(i,e));
	}
	bool ok=true;
	for(int i=0;i<v.size();i++){
		bool OK=false;
		for(int j=0;j<a;j++){
			int tmp=c[j];
			int cur=0;
			while(tmp%v[i].first==0){
				tmp/=v[i].first;
				cur++;
			}
			if(cur>=v[i].second){
				OK=true;break;
			}
		}
		if(!OK){ok=false;break;}
	}
	if(ok)printf("Yes\n");
	else printf("No\n");
}