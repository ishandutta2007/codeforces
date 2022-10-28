#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> count(26);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        count[c-'a']++;
    }
    string ans;
    for(int i=0;i<26;i++){
        if(count[i]!=0 && count[i]<k){
            int curr=count[i];
            if(count[i]>=k){
                cout<<char('a' + i)<<"\n";
                return;
            }
            for(int j=i+1;j<26;j++){
                curr+=count[j];
                if(curr>=k){
                    cout<<char('a' + j)<<"\n";
                    return;
                }
            }
        }
        else if(count[i]!=0){
            ans+='a'+i;
            count[i]-=k;
            break;
        }
    }
    int checkchar=0;
    for(int i=0;i<26;i++){
        if(count[i]){
            ++checkchar;
        }
    }
    if(checkchar>=2){
        for(int i=0;i<26;i++){
            for(int j=0;j<count[i];j++){
                ans+='a'+i;
            }
        }
        cout<<ans<<"\n";
        return;
    }
    bool check=0;
    for(int i=0;i<26;i++){
        while(count[i] >= k){
            if(check==1){
                ans.pop_back();
                check=0;
            }
            ans+='a'+i;
            count[i]-=k;
        }
        if(count[i]!=0){
            ans+='a'+i;
            check=1;
            k=count[i];
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}