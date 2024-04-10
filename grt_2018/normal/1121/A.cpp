#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int wanted[101];
pair<int,int>schols[101];
pair<int,int>student[101];
int gett[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0; i<n;i++) cin>>student[i].first;
    for(int i=0; i<n;i++) cin>>student[i].second;
    for(int i=0; i<n;i++) {
        if(schols[student[i].second].first<=student[i].first) {
            schols[student[i].second].first = student[i].first;
            schols[student[i].second].second = i+1;
        }
    }
    for(int i=1; i<=m;i++) gett[i] = schols[i].second;
    sort(gett+1,gett+m+1);
    int wsk = 0;
    for(int i=0; i<k;i++) cin>>wanted[i];
    sort(wanted,wanted+k);
    int ans=0;
    for(int i=0; i<k;i++) {
        while(wsk+1<=m&&gett[wsk+1]<=wanted[i]) wsk++;
        if(wanted[i]!=gett[wsk]) ans++;
    }
    cout<<ans;
    return 0;
}