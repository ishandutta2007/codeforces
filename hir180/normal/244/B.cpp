#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long l;
vector<l>vec;
int main(){
	l ten[10],a,b,c,n,m,e[9],sum=0,q[9],lo=0;
	for(l i=0;i<10;i++){
		if(i==0){
			ten[i]=1;
		}else{
			ten[i]=ten[i-1]*10;
		}
	}
	bool a1=0,a2=0,a3=0;
	for(l i=9;i>0;i--){
		for(l j=i-1;j>=0;j--){
			for(l k=0;k<=20000;k++){
				l r=k;
				for(l h=0;h<9;h++){
					e[h]=r%3;
					r/=3;
				}
				for(l h=0;h<9;h++){
					if(e[h]==1){
						a1=true;
						sum+=ten[8-h]*j;
					}else if(e[h]==2){
						a2=true;
						sum+=ten[8-h]*i;
					}else{
						if(a1==true || a2==true){
							a3=true;
						}
					}
				}
				if(a1){
					if(a2){
						if(a3){
							a1=0;
							a2=0;
							a3=0;
							sum=0;
							continue;
						}
					}
				}
				vec.push_back(sum);
				
				a1=0;
				a2=0;
				a3=0;
				sum=0;
			}
		}
	}
	sort(vec.begin(),vec.end());
	int ans=0;
	scanf("%lld",&n);
		for(int i=0;i<vec.size()-1;i++){
		if(vec[i]!=vec[i+1] && vec[i+1]<=n){
			ans++;
		}
	}
		if(n==1000000000){
		printf("%d\n",ans+1);
		}else{
		printf("%d\n",ans);
		}
	return 0;
}