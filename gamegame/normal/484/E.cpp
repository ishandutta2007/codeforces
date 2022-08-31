#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
struct seg{
    int left,right,pref,suff,maxi;
};
struct node{
    seg segment;
    int left,right;
};
vector<node>nodes(1);
int rt[100002];
seg cur[400001];
int last[400001];
int a[100001];
pair<int,int>b[100001];
int leaf[100001];
void build_tree(int id){
    if(id==1) cur[id]={1,n,0,0,0};
    else if(id&1) cur[id]={(cur[id/2].left+cur[id/2].right)/2+1,cur[id/2].right,0,0,0};
    else cur[id]={cur[id/2].left,(cur[id/2].left+cur[id/2].right)/2,0,0,0};
    if(cur[id].left==cur[id].right){
        leaf[cur[id].left]=id;
        nodes.push_back({cur[id],-1,-1});
        last[id]=nodes.size()-1;
    }
    else{
        build_tree(id*2); build_tree(id*2+1);
        nodes.push_back({cur[id],last[id*2],last[id*2+1]});
        last[id]=nodes.size()-1;
    }
}
void update(int id,int i){
    if(cur[id].left!=cur[id].right){
        cur[id].maxi=max(max(cur[id*2].maxi,cur[id*2+1].maxi),cur[id*2].suff+cur[id*2+1].pref);
        if(cur[id*2].pref==cur[id*2].right-cur[id*2].left+1) cur[id].pref=cur[id*2].pref+cur[id*2+1].pref;
        else cur[id].pref=cur[id*2].pref;
        if(cur[id*2+1].suff==cur[id*2+1].right-cur[id*2+1].left+1) cur[id].suff=cur[id*2].suff+cur[id*2+1].suff;
        else cur[id].suff=cur[id*2+1].suff;
        nodes.push_back({cur[id],last[id*2],last[id*2+1]});
        last[id]=nodes.size()-1;
    }
    if(id!=1) update(id/2,i);
}
seg maxi(int id,int left,int right){
    seg treeid=nodes[id].segment;
    if(left==treeid.left && right==treeid.right){
        return treeid;
    }
    int mid=(treeid.left+treeid.right)/2;
    if(left<=mid && right>mid){
        seg ll=maxi(nodes[id].left,left,mid),rr=maxi(nodes[id].right,mid+1,right),ans;
        ans.maxi=max(max(ll.maxi,rr.maxi),ll.suff+rr.pref);
        if(ll.pref==ll.right-ll.left+1) ans.pref=ll.pref+rr.pref;
        else ans.pref=ll.pref;
        if(rr.suff==rr.right-rr.left+1) ans.suff=ll.suff+rr.suff;
        else ans.suff=rr.suff;
        ans.left=left;
        ans.right=right;
        return ans;
    }
    else if(left<=mid){
        return maxi(nodes[id].left,left,right);
    }
    else{
        return maxi(nodes[id].right,left,right);
    }
}
int main(){
    ios::sync_with_stdio(0);
    int l,r,w;
    cin >> n;
    for(int i=1; i<=n ;i++){
        cin >> a[i];
        b[i]=make_pair(a[i],i);//a,b
    }
    build_tree(1);//cur,nodes,leaf
    sort(b+1,b+n+1);
    rt[n+1]=last[1];
    for(int i=n; i>=1 ;i--){
        cur[leaf[b[i].second]].pref=cur[leaf[b[i].second]].suff=cur[leaf[b[i].second]].maxi=1;
        nodes.push_back({cur[leaf[b[i].second]],-1,-1});
        last[leaf[b[i].second]]=nodes.size()-1;
        update(leaf[b[i].second],i);//cur,nodes
        rt[i]=last[1];
    }
    cin >> m;
    for(int i=1; i<=m ;i++){
        cin >> l >> r >> w;
        int left=1,right=n,mid;
        while(left!=right){
            mid=(left+right+1)/2;
            if(maxi(rt[mid],l,r).maxi>=w){
                left=mid;
            }
            else{
                right=mid-1;
            }
        }
        cout << b[left].first << endl;
    }
}