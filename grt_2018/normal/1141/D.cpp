#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150*1000+1;
int n;
vector<int>cntl[27];
vector<int>cntr[27];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        char c;
        cin>>c;
        if(c=='?') cntl[0].push_back(i);
        else cntl[c-'a'+1].push_back(i);
    }
    for(int i=0; i<n;i++) {
        char c;
        cin>>c;
        if(c=='?') cntr[0].push_back(i);
        else cntr[c-'a'+1].push_back(i);
    }
    for(int i=1; i<=26;i++) {
        ans+=min(cntl[i].size(),cntr[i].size());
    }
    ans+=min((int)cntl[0].size()+(int)cntr[0].size(),n-ans);
    cout<<ans<<"\n";
    for(int i=1; i<=26;i++) {
        while(cntl[i].size()!=0&&cntr[i].size()!=0) {
            cout<<cntl[i].back()+1<<" "<<cntr[i].back()+1<<"\n";
            cntl[i].pop_back();
            cntr[i].pop_back();
        }
    }
    int wsk1=26;
    while(wsk1>=0&&cntr[0].size()!=0) {
        while(cntl[wsk1].size()>0) {
            cout<<cntl[wsk1].back()+1<<" "<<cntr[0].back()+1<<"\n";
            cntr[0].pop_back();
            cntl[wsk1].pop_back();
            if(cntr[0].size()==0) break;
        }
        wsk1--;
    }
    wsk1=26;
    while(wsk1>=0&&cntl[0].size()!=0) {
        while(cntr[wsk1].size()>0) {
            cout<<cntl[0].back()+1<<" "<<cntr[wsk1].back()+1<<"\n";
            cntl[0].pop_back();
            cntr[wsk1].pop_back();
            if(cntl[0].size()==0) break;
        }
        wsk1--;
    }
    while(cntr[0].size()>0&&cntl[0].size()>0) {
        cout<<cntl[0].back()+1<<" "<<cntr[0].back()+1<<"\n";
        cntl[0].pop_back();
        cntr[0].pop_back();
    }
    return 0;
}