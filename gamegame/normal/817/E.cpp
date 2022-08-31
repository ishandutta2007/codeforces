#include<iostream>
using namespace std;
int cnt[3000001];
int c[3000001][2];
int size=1;
int q;
void insert(int num){
    int ptr=0;
    for(int i=30; i>=0 ;i--){
        int newi=((num&(1<<i))!=0);
        if(c[ptr][newi]==0){
            c[ptr][newi]=size;
            size++;
        }
        cnt[c[ptr][newi]]++;
        ptr=c[ptr][newi];
    }
}
void remove(int num){
    int ptr=0;
    for(int i=30; i>=0 ;i--){
        int newi=((num&(1<<i))!=0);
        cnt[c[ptr][newi]]--;
        ptr=c[ptr][newi];
    }
}
int answer(int p,int l){
    int ans=0,ptr=0;
    for(int i=30; i>=0 ;i--){
        int newi=(((l&(1<<i))^(p&(1<<i)))!=0);
        if(l&(1<<i)){
            ans+=cnt[c[ptr][1^newi]];
        }
        ptr=c[ptr][newi];
        if(ptr==0) return ans;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> q;
    int t,p,l;
    for(int i=1; i<=q ;i++){
        cin >> t;
        if(t==1){
            cin >> p;
            insert(p);
        }
        else if(t==2){
            cin >> p;
            remove(p);
        }
        else{
            cin >> p >> l;
            cout << answer(p,l) << '\n';
        }
    }
}