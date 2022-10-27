#include <bits/stdc++.h>

using namespace std;

int n,m,ns,ne,v;
int sta[100005], ele[100005];

int bs1(int x){
    if(ns == 0)return 0;
    int l = 1, r = ns;
    if(sta[l] > x)return 0;
    while(l < r){
        int m = l + (r-l+1)/2;
        if(sta[m] < x){
            l = m;
        }else{
            r = m-1;
        }
    }
    return l;
}

int bs2(int x){
    if(ne == 0)return 0;
    int l = 1, r = ne;
    if(ele[l] > x)return 0;
    while(l < r){
        int m = l + (r-l+1)/2;
        if(ele[m] < x){
            l = m;
        }else{
            r = m-1;
        }
    }
    return l;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>ns>>ne>>v;
    for(int i = 1; i <= ns; i++){
        cin>>sta[i];
    }
    for(int i = 1; i <= ne; i++){
        cin>>ele[i];
    }
    int q, x1, x2, y1, y2;
    cin>>q;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        if(x1 == x2){
            cout<<abs(y1 - y2)<<endl;
        }else{
            int ans = INT_MAX;
            if(y1 > y2)swap(y1, y2);
            if(x1 > x2)swap(x1, x2);
            int s1, s2, s3, e1, e2, e3;
            s1 = bs1(y1), s2 = bs1(y2);
            e1 = bs2(y1), e2 = bs2(y2);
            s2 -= s1, e2 -= e1;
            s3 = ns - s1 - s2, e3 = ne - e1 - e2;
            if(s1 > 0){
                ans = min(ans, x2 - x1 + y1 + y2 - 2*sta[s1]);
            }
            if(s2 > 0){
                ans = min(ans, x2 - x1 + y2 - y1);
            }
            if(s3 > 0){
                ans = min(ans, x2 - x1 + 2*sta[s1 + s2 + 1] - y1 - y2);
            }
            int tmp = (x2 - x1)/v;
            if((x2 - x1)%v != 0)tmp++;
            if(e1 > 0){
                ans = min(ans, tmp + y1 + y2 - 2*ele[e1]);
            }
            if(e2 > 0){
                ans = min(ans, tmp + y2 - y1);
            }
            if(e3 > 0){
                ans = min(ans, tmp + 2*ele[e1 + e2 + 1] - y1 - y2);
            }
            cout<<ans<<endl;
        }
    }
}