#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
const int N=100005;
using namespace std;  
struct Node{  
    int val,idx;  
    bool operator<(const Node n)const{  
        return val<n.val;  
    }  
}a[N];  
int n,m,in[N*2],cnt;  
vector<int>edge[N*2];  
queue<int>que;  
void add(int u,int v){  
    in[v]++;  
    edge[u].push_back(v);  
}  
int main(){  
    cin>>n>>m;  
    for(int i=0;i<n;i++){  
        for(int j=0;j<m;j++){  
            scanf("%d",&a[j].val);  
            a[j].idx=j;  
        }  
        sort(a,a+m);  
        for(int j=0;j<m;j++){  
            if(a[j].val==-1) continue;  
            if(!j||a[j].val!=a[j-1].val) cnt++;  
            add(a[j].idx,m+cnt+1);  
            add(m+cnt,a[j].idx);  
        }  
        cnt++;  
    }  
    for(int i=0;i<m+cnt;i++)  
        if(!in[i])   
            que.push(i);  
    int ans[N],tot=0;  
    while(!que.empty()){  
        int u=que.front();que.pop();  
        if(u<m)  
            ans[tot++]=u;  
        for(int i=0;i<edge[u].size();i++){  
            int v=edge[u][i];  
            in[v]--;  
            if(!in[v])  
                que.push(v);  
        }  
    }  
    if(tot<m) puts("-1");  
    else{  
        for(int i=0;i<m;i++)  
            cout<<ans[i]+1<<(i==m-1?"\n":" ");  
    }  
    return 0;  
}