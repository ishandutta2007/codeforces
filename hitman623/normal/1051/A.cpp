#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s;
void solve(){
    int l=0,u=0,d=0;
    cin>>s;
    for(auto i:s){
        if(isalpha(i)){
            if(islower(i)) l++;
            else u++;
        }
        else d++;
    }
    if(d and l and u) cout<<s<<endl;
    else if(d==0 and l==0){
        s[0]='1';
        s[1]='a';
        cout<<s<<endl;
    }
    else if(d==0 and u==0){
        s[0]='1';
        s[1]='A';
        cout<<s<<endl;     
    }
    else if(l==0 and u==0){
        s[0]='a';
        s[1]='A';
        cout<<s<<endl;
    }
    else if(d==0){
        for(auto &i:s){
            if(islower(i) and l>1){
                i='1';
                cout<<s<<endl;
                return;
            }
            if(isupper(i) and u>1){
                i='1';
                cout<<s<<endl;
                return;
            }
        }
    }
    else if(l==0){
        for(auto &i:s){
            if(isdigit(i) and d>1){
                i='a';
                cout<<s<<endl;
                return;
            }
            if(isalpha(i) and u>1){
                i='a';
                cout<<s<<endl;
                return;                
            }
        }
    }
    else{
        for(auto &i:s){
            if(isdigit(i) and d>1){
                i='A';
                cout<<s<<endl;
                return;
            }
            if(isalpha(i) and l>1){
                i='A';
                cout<<s<<endl;
                return;      
            }
        }        
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}