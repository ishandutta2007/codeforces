#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
vector<int> prime;
int isprime[3000005];
int number[3000005];
int Max[3000005];
void Find(){
	prime.pb(0);
	fill(isprime,isprime+3000005,1);
	for(int i = 2;i<3000005;i++){
		if(isprime[i]){
			number[i]=prime.size();
			prime.pb(i);
			for(int j=i*2;j<3000005;j+=i){
				isprime[j]=0;
				Max[j]=max(Max[j],j/i);
			}
		}
	}
}
int main(){
	Find();
	int n;
	scanf("%d",&n);
	multiset<int> s;
	for(int i = 0;i<2*n;i++){
		int x;
		scanf("%d",&x);
		s.insert(x);
	}
	vector<int> v;
	while(!s.empty()){
		int x=*s.rbegin();
		s.erase(s.find(x));
		if(isprime[x]){
			v.pb(number[x]);
			s.erase(s.find(number[x]));
		}
		else{
			v.pb(x);
			s.erase(s.find(Max[x]));
		}
		//printf("%lld\n",s.size());
	}
	for(auto it:v)
	printf("%d ",it);
	printf("\n");
}
/*
aaaa
aaba
abaa
baaa
baba
*/