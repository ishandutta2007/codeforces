#include <bits/stdc++.h>

using namespace std;

int tree[5000005][2];
int val[5000005][2];
int ptr = 1;

void addNum(int n){
    int tmp = 0;
    for(int i = 29; i >= 0; i--){
        int c = ((n&(1<<i)) > 0);
        if(tree[tmp][c] == -1){
            tree[tmp][c] = ptr; ptr++;
            val[tmp][c] = 1;
            tmp = tree[tmp][c];
        }else{
            val[tmp][c]++;
            tmp = tree[tmp][c];
        }
    }
}

void removeNum(int n){
    int tmp = 0;
    for(int i = 29; i >= 0; i--){
        int c = ((n&(1<<i)) > 0);
        val[tmp][c]--;
        tmp = tree[tmp][c];
    }
}

int searchMin(int n){
    int ans = 0, tmp = 0;
    for(int i = 29; i >= 0; i--){
        int c = ((n&(1<<i)) > 0);
        if((tree[tmp][c] != -1) && (val[tmp][c] > 0)){
            tmp = tree[tmp][c];
            if(c == 1)ans = ans|(1<<i);
        }else{
            tmp = tree[tmp][1-c];
            if(c == 0)ans = ans|(1<<i);
        }
    }
    return ans;
}

int main(){
    memset(tree, -1, sizeof(tree));
    memset(val, 0, sizeof(val));
    int n,x;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>x;
        addNum(x);
    }
    for(int i = 0; i < n; i++){
        int ans = searchMin(a[i]);
        cout<<(ans^a[i])<<" ";
        removeNum(ans);
    }
    cout<<endl;
}