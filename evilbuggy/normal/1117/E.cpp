#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 10005;

struct Node{
    char a[3];
    bool operator<(const Node &b) const{
        if(a[0] != b.a[0])return a[0] < b.a[0];
        if(a[1] != b.a[1])return a[1] < b.a[1];
        return a[2] < b.a[2];
    }
};

Node a[maxn], b[maxn];

void gen(){
    int ptr = 0;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            for(int k = 0; k < 26; k++){
                a[ptr].a[0] = char('a' + i);
                a[ptr].a[1] = char('a' + j);
                a[ptr].a[2] = char('a' + k);
                ptr++;
                if(ptr == maxn)break;
            }
            if(ptr == maxn)break;
        }
        if(ptr == maxn)break;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    string s;
    cin>>s;
    gen();
    int n = s.size();
    for(int i = 0; i < 3; i++){
        string tmp = "";
        for(int j = 0; j < n; j++){
            tmp += a[j].a[i];
        }
        cout<<"? "<<tmp<<endl;
        fflush(stdout);
        cin>>tmp;
        for(int j = 0; j < n; j++){
            b[j].a[i] = tmp[j];
        }
    }
    map<Node, int> arr;
    for(int i = 0; i < n; i++){
        arr[a[i]] = i;
    }
    map<int,int> perm;
    for(int i = 0; i < n; i++){
        perm[i] = arr[b[i]];
    }
    string t = s;
    for(int i = 0; i < n; i++){
        t[perm[i]] = s[i];
    }
    cout<<"! "<<t<<endl;
}