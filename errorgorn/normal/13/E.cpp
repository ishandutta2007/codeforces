#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,q;
int sqrt_n;
int biggest_bucket;
struct data{
	int jump;
	int leap;
	int succ;
	int moves;
};
data arr[100005];
void comp(int i){ //recompute the ith bucket
	i++;
	i*=sqrt_n;
	int upper=min(i-1,n-1);
	for (int x=0;x<sqrt_n;x++){
		i--;
		if (i>n) continue;
		if (arr[i].jump+i>upper){
			arr[i].leap=arr[i].jump;
			arr[i].succ=i;
			arr[i].moves=1;
		}
		else {
			arr[i].leap=arr[i+arr[i].jump].leap+arr[i].jump;
			arr[i].succ=arr[i+arr[i].jump].succ;
			arr[i].moves=arr[i+arr[i].jump].moves+1;
		}
	}
}
void print(){
    for (int x=0;x<n;x++){
        printf("%d %d %d %d\n",arr[x].jump,arr[x].leap,arr[x].moves,arr[x].succ);
    }
}
int main(){
	scanf("%d%d",&n,&q);
	sqrt_n=sqrt(n);
	biggest_bucket=(n-1)/sqrt_n;
	for (int x=0;x<n;x++){
		scanf("%d",&arr[x].jump);
	}
	for (int x=0;x<=((n-1)/sqrt_n)+1;x++)comp(x);
	int type;
	int a,b;
	//print();
	while (q--){
		scanf("%d",&type);
		if (type){
			scanf("%d",&a);
			a--;
			b=0;
			while (true){
				b+=arr[a].moves;
				if (a+arr[a].leap>=n){
					printf("%d %d\n",arr[a].succ+1,b);
					break;
				}
				else{
					a+=arr[a].leap;
				}
			}
		}
		else {
			scanf("%d%d",&a,&b);
			arr[a-1].jump=b;
			comp((a-1)/sqrt_n);
		}
	}
}