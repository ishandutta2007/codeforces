#include<iostream>
using namespace std;
struct seg{
	long long int left,right,sum,maxi,maxnum;
};
int n,m;
long long int leaf[100001],a[100001];
seg tree[400001];
void build_tree(int id){
	if(id==1) tree[id]={1,n,0,0,0};
	else if(id&1) tree[id]={(tree[id/2].left+tree[id/2].right)/2+1,tree[id/2].right,0,0,0};
	else tree[id]={tree[id/2].left,(tree[id/2].left+tree[id/2].right)/2,0,0,0};
	if(tree[id].left!=tree[id].right){
		build_tree(id*2);build_tree(id*2+1);
	}
	else leaf[tree[id].left]=id;
}
void update(int id){
	if(tree[id].left!=tree[id].right){
		tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
		if(tree[id*2].maxi>tree[id*2+1].maxi){
			tree[id].maxi=tree[id*2].maxi;
			tree[id].maxnum=tree[id*2].maxnum;
		}
		else{
			tree[id].maxi=tree[id*2+1].maxi;
			tree[id].maxnum=tree[id*2+1].maxnum;
		}
	}
	if(id!=1) update(id/2);
}
long long sum(int id,int left,int right){
	if(tree[id].left==left && right==tree[id].right){
		return tree[id].sum;
	}
	int mid=(tree[id].left+tree[id].right)/2;
	if(left<=mid && right>mid){
		return sum(id*2,left,mid)+sum(id*2+1,mid+1,right);
	}
	else if(left<=mid){
		return sum(id*2,left,right);
	}
	else{
		return sum(id*2+1,left,right);
	}
}
pair<long long,int> maxi(int id,int left,int right){
	if(tree[id].left==left && right==tree[id].right){
		return make_pair(tree[id].maxi,tree[id].maxnum);
	}
	int mid=(tree[id].left+tree[id].right)/2;
	if(left<=mid && right>mid){
		return max(maxi(id*2,left,mid),maxi(id*2+1,mid+1,right));
	}
	else if(left<=mid){
		return maxi(id*2,left,right);
	}
	else{
		return maxi(id*2+1,left,right);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	build_tree(1);
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		tree[leaf[i]]={i,i,a[i],a[i],i};
		update(leaf[i]);
	}
	int t,l,r,x,k;
	for(int i=1; i<=m ;i++){
		cin >> t;
		if(t==1){
			cin >> l >> r;
			cout << sum(1,l,r) << endl;
		}
		else if(t==2){
			cin >> l >> r >> x;
			pair<long long,int>cur=maxi(1,l,r);
			while(cur.first>=x){
				k=cur.second;
				tree[leaf[k]].sum=tree[leaf[k]].maxi=cur.first%x;
				update(leaf[k]);
				cur=maxi(1,l,r);
			}
		}
		else{
			cin >> k >> x;
			tree[leaf[k]]={k,k,x,x,k};
			update(leaf[k]);
		}
	}
}