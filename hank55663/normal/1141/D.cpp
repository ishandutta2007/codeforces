#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> l[30];
    vector<int> r[30];
    char c[150005];
    scanf("%s",c);
    for(int i = 0 ;i<n;i++){
        if(c[i]=='?')
        l[26].pb(1+i);
        else
        l[c[i]-'a'].pb(i+1);
    }
    scanf("%s",c);
    for(int i = 0 ;i<n;i++){
        if(c[i]=='?')
        r[26].pb(1+i);
        else{
            r[c[i]-'a'].pb(i+1);
        }
    }
    vector<pii> v;
    vector<int> ll,rr;
    for(int i = 0 ;i<26 ;i++){
        for(int j = 0 ;j < max(l[i].size(),r[i].size());j++){
            if(j<l[i].size()&&j<r[i].size()){
                v.pb(mp(l[i][j],r[i][j]));
            }
            if(j>=l[i].size()){
                rr.pb(r[i][j]);
            }
            if(j>=r[i].size()){
                ll.pb(l[i][j]);
            }
        }
    }
    //printf("?\n");
    for(int i = 0 ;i<l[26].size() ; i++){
        if(rr.size()){
            v.pb(mp(l[26][i],rr.back()));
            rr.pop_back();
        }
        else
        {
            ll.pb(l[26][i]);
        }
    }
    for(auto it:r[26]){
        if(ll.size()){
            v.pb(mp(ll.back(),it));
            ll.pop_back();
        }
    }
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d %d\n",it.x,it.y);
}