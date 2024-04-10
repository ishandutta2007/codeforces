#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=3e5+1;
vector<char> arr[2];
int ls[2];
int rs[2];
char ans[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string a;
    cin>>a;
    int n=sz(a);
    for(int i=0;i<n;i++){
        arr[0].push_back(a[i]);
    }
    cin>>a;
    for(int i=0;i<n;i++){
        arr[1].push_back(a[i]);
    }
    rs[0]=(n-1)/2;
    rs[1]=n-1;
    ls[1]=n-n/2;
    sort(arr[0].begin(),arr[0].end());
    sort(arr[1].begin(),arr[1].end());
    int l=0,r=n-1;
    for(int i=0;i<n;i++){
        if(i%2){
            if(arr[0][ls[0]]>=arr[1][rs[1]]&&i!=n-1){
                ans[r--]=arr[1][ls[1]];
                ls[1]++;
            }
            else {
                ans[l++]=arr[1][rs[1]];
                rs[1]--;
            }
        }
        else{
            if(arr[0][ls[0]]>=arr[1][rs[1]]&&i!=n-1){
                ans[r--]=arr[0][rs[0]];
                rs[0]--;
            }
            else {
                ans[l++]=arr[0][ls[0]];
                ls[0]++;
            }
        }
    }
    for(int i=0;i<n;i++)printf("%c",ans[i]);
    return 0;
}