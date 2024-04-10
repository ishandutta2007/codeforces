#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct seg{
	int org,sor,l,r;
};
bool cmp1(seg i,seg j){
	return i.l>j.l;
};
bool cmp2(seg i,seg j){
	return i.r<j.r;
};
int bit[200001],n;
int pre(int i){
	int sum=0;
	while(i>0){
		sum+=bit[i];
		i-=i&(-i);
	}
	return sum;
}
void update(int i){
	while(i<=n){
		bit[i]++;
		i+=i&(-i);
	}
}
int main(){
	cin >> n;
	seg a[n+1];
	int ans[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i].l >> a[i].r;
		a[i].org=i;
		ans[i]=0;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1; i<=n ;i++){
		a[i].sor=i;
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=0; i<=n ;i++){
		bit[i]=0;
	}
	for(int i=1; i<=n ;i++){
		update(a[i].sor);
		ans[a[i].org]=pre(a[i].sor-1);
	}
	for(int i=1; i<=n ;i++){
		cout << ans[i] << endl;
	}
}