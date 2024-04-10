#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000*100+1;
int n,base;
int a[MAXN];
int b[MAXN];
int trie[31*MAXN][2], id = 1;
int ile[31*MAXN];

void add(int x) {
    int i=0,v=0;
    ile[v]++;
    while(i<=base) {
        //cout<<x<<" "<<(x&(1<<(base-i)))<<"\n";
        if(trie[v][(x&(1<<(base-i)))>0]==-1)
            v = trie[v][(x&(1<<(base-i)))>0] = id++;
        else
            v = trie[v][(x&(1<<(base-i)))>0];
        ile[v]++;
        i++;
    }
}

int query(int x) {
    int i=0,v=0,ans=0;
    while(i<=base) {
        if(trie[v][(x&(1<<(base-i)))>0]==-1) {
            v = trie[v][1-((x&(1<<(base-i)))>0)];
            ans+=(1-((x&(1<<(base-i)))>0))*(1<<(base-i));
        }
        else {
            v = trie[v][(x&(1<<(base-i)))>0];
            ans+=((x&(1<<(base-i)))>0)*(1<<(base-i));
        }
        i++;
    }
    return ans;
}

void usun(int x) {
    int i=0,v=0;
    ile[v]--;
    while(i<=base) {
        if(trie[v][(x&(1<<(base-i)))>0]==-1) break;
        if(ile[trie[v][(x&(1<<(base-i)))>0]]==1) {
            trie[v][(x&(1<<(base-i)))>0]=-1;
            break;
        }
        v = trie[v][(x&(1<<(base-i)))>0];
        ile[v]--;
        i++;
    }
}

void coutTree() {
    for(int i=0; i<30*n;i++) {
        cout<<i<<" : "<<trie[i][0]<<" "<<trie[i][1]<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
        int po=1,k=0;
        while(po*2<=a[i]) {
            k++;
            po*=2;
        }
        base=max(base,k);
    }
    for(int i=0; i<n;i++) {
        cin>>b[i];
        int po=1,k=0;
        while(po*2<=b[i]) {
            k++;
            po*=2;
        }
        base=max(base,k);
    }
    for(int i=0; i<30*n;i++) trie[i][0] = trie[i][1] = -1;
    for(int i=0; i<n;i++) {
        add(b[i]);
    }
    //cout<<base<<"\n";
    //coutTree();
    for(int i=0; i<n;i++) {
        int w = query(a[i]);
        cout<<(w^a[i])<<" ";
        usun(w);
    }
    return 0;
}