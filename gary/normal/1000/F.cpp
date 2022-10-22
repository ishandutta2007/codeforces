/*
	Author GaryMr
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // less<int>
	priority_queue<vector<>, greater<> > pq2; // greater<int>
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[500001],q,p[500001],now[500001],last[500001],tree[4000001];
map<int,int> num;
map<int,int> m;
map<pair<int,int>,int> ans;
vector<int> v[500001];
vector<pair<int,int> > unonline;
void build(int k,int l,int r){
//	cout<<k<<":"<<"{"<<l<<","<<r<<"}"<<endl;
	if(l==r-1){
		num[l]=k;
		tree[k]=last[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k*2,l,mid);
	build(k*2+1,mid,r);
	tree[k]=min(tree[k*2],tree[k*2+1]);
}
void change(int Num){
	tree[num[Num]]=last[Num];
//	cout<<"{"<<Num<<" "<<num[Num]<<"}"<<endl; 
	int Last=((num[Num])>>1);
	while(Last){
		tree[Last]=min(tree[Last<<1],tree[(Last<<1)+1]);
		Last=Last>>1;
	}
}
int findmin(int k,int a,int b,int l,int r){
	if(l>=b||r<=a) return 0x3f3f3f3f;
	if(r<=b&&l>=a){
//	cout<<tree[k]<<" "<<a<<" "<<b<<" "<<l<<" "<<r<<endl;
	return tree[k];
	 
	}
	int mid = (l+r)>>1;
	return min(findmin(k<<1,a,b,l,mid),findmin((k<<1)+1,a,b,mid,r));
}
int main(){
	int startn;
	scanf("%d",&n);startn=n;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		p[a[i]]=now[a[i]];
//		cout<<a[i]<<"S"<<endl;
		now[a[i]]=i;
		last[i]=p[a[i]];
	}
	n=(1<<int(ceil(log2(double(n))))); 
	build(1,1,n+1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		unonline.push_back({l,r});
		m[r]=1;
		v[r].push_back(l);
	}
//	cout<<endl;
	map<int,int> tot;stack<int> zero;
	for(int i=1;i<=startn;i++){
//		cout<<a[i]<<endl; 
//		cout<<last[i]<<" "<<i<<endl; 
		tot[a[i]]++;
		if(last[i]){
			last[last[i]]=0x3f3f3f3f;
			change(last[i]);	
		}
		else{
//			cout<<i<<endl;
			zero.push(i);
//			cout<<"!"<<i<<endl;
//			a[0]=a[i];
		}
		if(m[i]){
			for(unsigned int j=0;j<v[i].size();j++){
//							for(int k=1;k<=n;k++) cout<<tree[num[k]]<<" ";cout<<endl;
				int tmp=findmin(1,v[i][j],i+1,1,n+1);
//				cout<<tmp<<" "<<v[i][j]<<" "<<i+1<<" "<<endl;
				if(tmp==0){
					while(!zero.empty()){//cout<<a[zero.front()]<<endl;
						if(tot[a[zero.top()]]==1){
							ans[{v[i][j],i}] = a[zero.top()];
//							zero.pop();
							break;
						}
						zero.pop();
					}
					continue;
				} 
				if(tmp<v[i][j]) ans[{v[i][j],i}] = a[tmp];
				else ans[{v[i][j],i}]=0;
			}
		}
	}
	for(unsigned int i=0;i<unonline.size();i++){
		printf("%d\n",ans[unonline[i]]);
	}
	return 0;
}