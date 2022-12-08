#include<bits/stdc++.h>
using namespace std;
const int M=1e8;
vector<int>X,Y,ans;
int pos;
int query(int X,int Y) {
	printf("0 %d %d\n",X,Y);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void solve(int L,int R) {
	if(L>R)return;
	int mid=(L+R)/2;
	int S=query(mid,mid);
	if(!S)ans.push_back(mid),S=1;
	else pos=mid;
	solve(L,mid-S);
	solve(mid+S,R);
}
int main() {
	solve(-M,M);
	for(int i:ans) {
		if(!query(pos,i))X.push_back(i);
		if(!query(i,pos))Y.push_back(i);
	}
	cout<<1<<' '<<Y.size()<<' '<<X.size()<<endl;
	for(int i:Y)printf("%d ",i);puts("");
	for(int i:X)printf("%d ",i);puts("");
	return 0;
}