#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*('')*/
int decr[200000];
int main(){
	vector<int>vec;
	int n,m,a;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(!vec.size()){
			vec.push_back(a);
		}else{
			if(vec[vec.size()-1]!=a){
				vec.push_back(a);
			}
		}
	}
	decr[vec[0]]++;
	decr[vec[vec.size()-1]]++;
	for(int i=1;i<vec.size()-1;i++){
		if(vec[i-1]==vec[i+1]){
			decr[vec[i]]+=2;
		}else{
			decr[vec[i]]++;
		}
	}
	int max=0,ans;
	for(int i=1;i<=m;i++){
		if(max<decr[i]){
			max=decr[i];
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}