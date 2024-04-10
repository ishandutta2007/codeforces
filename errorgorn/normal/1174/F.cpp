#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> al[200005];
int depth[200005];
int subtree[200005];
int heavy[200005];
void dfs(int i,int p){
    subtree[i]=1;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (*it==p) continue;
        depth[*it]=depth[i]+1;
        dfs(*it,i);
        subtree[i]+=subtree[*it];
        if (subtree[*it]>subtree[heavy[i]]){
            heavy[i]=*it;
        }
    }
}
int main(){
    cin>>n;
    int a,b;
    for (int x=1;x<n;x++){
        cin>>a>>b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    dfs(1,-1);

    cout<<"d 1"<<endl;
    int height;
    cin>>height;
    if (height==0){
        cout<<"! 1"<<endl;
        return 0;
    }

    int root=1,h;
    int diff;
    int goal;

    while (true){
        h=root;
        while (heavy[h]) h=heavy[h];
        cout<<"d "<<h<<endl;
        cin>>diff;
        if (depth[h]-height==diff){
            h=root;
            while (depth[h]!=height) h=heavy[h];
            cout<<"! "<<h<<endl;
            return 0;
        }
        else{
            goal=height-(height+diff-depth[h])/2;
            h=root;
            while (depth[h]!=goal) h=heavy[h];
            cout<<"s "<<h<<endl;
            cin>>root;
        }
    }
}