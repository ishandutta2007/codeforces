#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
vector<long long>vec;
int main(){
	long long r;
	scanf("%lld",&r);
	if(r%3!=0){
		puts("0");
		return 0;
	}
	r/=3;
	for(long long i=1;i*i<=r;i++){
		if(r%i==0){
			vec.pb(i);
			if(i*i!=r){
				vec.pb(r/i);
			}
		}
	}
	sort(vec.begin(),vec.end());
	int ret=0;
	for(long long i=1;i*i*i<=r;i++){
                if(r%i!=0) continue;
		long long s;
		s=r/i;
		int F=lower_bound(vec.begin(),vec.end(),i)-vec.begin();
		for(int d=F;;d++){
			if(vec[d]*vec[d]>s){
				break;
			}
			if(s%vec[d]==0){
				long long a,b,c,D,e,f;
				a=i;
				b=vec[d];
				c=s/vec[d];
				if((a+b+c)%2==0 && a+b>c){
					D=(a+b+c)/2-a;
					e=(a+b+c)/2-b;
					f=(a+b+c)/2-c;
					if(D==f){
						ret++;
					}else if((D==e) || (e==f)){
						ret+=3;
					}else{
						ret+=6;
					}
				}
			}
		}
	}
	printf("%d\n",ret);
}