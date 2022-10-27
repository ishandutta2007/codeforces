#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m;
    cin>>n>>m;
    if(m == 1){
        if(n == 2){
            cout<<0<<endl;
            cout<<"1 1\n2 1\n1 1"<<endl;
        }else{
            cout<<1<<endl;
            cout<<n<<" 1 1 1"<<endl;
            for(int i = 1; i <= n; i++){
                cout<<i<<" 1"<<endl;
            }
            cout<<"1 1"<<endl;
        }
    }else if(n == 1){
        if(m == 2){
            cout<<0<<endl;
            cout<<"1 1\n1 2\n1 1"<<endl;
        }else{
            cout<<1<<endl;
            cout<<1<<" "<<m<<" 1 1"<<endl;
            for(int i = 1; i <= m; i++){
                cout<<"1 "<<i<<endl;
            }
            cout<<"1 1"<<endl;
        }
    }else if(n%2 == 0){
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        for(int i = 1; i <= n; i++){
            if(i&1){
                for(int j = 2; j <= m; j++){
                    cout<<i<<" "<<j<<endl;
                }
            }else{
                for(int j = m; j >= 2; j--){
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        for(int i = n; i >= 1; i--){
            cout<<i<<" "<<1<<endl;
        }
    }else if(m%2 == 0){
        cout<<0<<endl;
        cout<<1<<" "<<1<<endl;
        for(int i = 1; i <= m; i++){
            if(i&1){
                for(int j = 2; j <= n; j++){
                    cout<<j<<" "<<i<<endl;
                }
            }else{
                for(int j = n; j >= 2; j--){
                    cout<<j<<" "<<i<<endl;
                }
            }
        }
        for(int i = m; i >= 1; i--){
            cout<<1<<" "<<i<<endl;
        }
    }else{
        cout<<1<<endl;
        cout<<n<<" "<<m<<" "<<n<<" "<<1<<endl;
        cout<<1<<" "<<1<<endl;
        for(int i = 1; i <= n; i++){
            if(i&1){
                for(int j = 2; j <= m; j++){
                    cout<<i<<" "<<j<<endl;
                }
            }else{
                for(int j = m; j >= 2; j--){
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        for(int i = n; i >= 1; i--){
            cout<<i<<" "<<1<<endl;
        }
    }
}