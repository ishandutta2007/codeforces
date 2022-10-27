#include <bits/stdc++.h>

using namespace std;

vector<int> a[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin>>n;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i++){
        cin>>x;
        a[x].push_back(i);
    }
    vector<int> one, two, gt;
    for(int i = 0; i < 105; i++){
        if(a[i].size() == 1)one.push_back(i);
        if(a[i].size() == 2)two.push_back(i);
        if(a[i].size() > 2)gt.push_back(i);
    }
    int sum = 0;
    char ans[n+1];
    for(int i = 0; i < one.size(); i++){
        if(sum == 0){
            ans[a[one[i]][0]] = 'A';
            sum++;
        }else{
            ans[a[one[i]][0]] = 'B';
            sum--;
        }
    }
    for(int i = 0; i < two.size(); i++){
        ans[a[two[i]][0]] = 'A';
        ans[a[two[i]][1]] = 'B';
    }

    int ind;

    if(sum == 0){
        if(gt.size()%2 == 0){
            for(int i = 0; i < gt.size(); i++){
                ind = gt[i];
                if(sum == 0){
                    ans[a[ind][0]] = 'A';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'B';
                    }
                    sum++;
                }else{
                    ans[a[ind][0]] = 'B';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'A';
                    }
                    sum--;
                }
            }
        }else{
            ind = gt[0];
            for(int j = 0; j < a[ind].size(); j++){
                ans[a[ind][j]] = 'A';
            }
            for(int i = 1; i < gt.size(); i++){
                ind = gt[i];
                if(sum == 0){
                    ans[a[ind][0]] = 'A';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'B';
                    }
                    sum++;
                }else{
                    ans[a[ind][0]] = 'B';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'A';
                    }
                    sum--;
                }
            }
        }
    }else{
        if(gt.size()%2 == 0){
            for(int i = 1; i < gt.size(); i++){
                ind = gt[i];
                if(sum == 0){
                    ans[a[ind][0]] = 'A';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'B';
                    }
                    sum++;
                }else{
                    ans[a[ind][0]] = 'B';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'A';
                    }
                    sum--;
                }
            }
            if(gt.size() > 0){
                ind = gt[0];
                for(int j = 0; j < a[ind].size(); j++){
                    ans[a[ind][j]] = 'A';
                }
            }
        }else{
            for(int i = 0; i < gt.size(); i++){
                ind = gt[i];
                if(sum == 0){
                    ans[a[ind][0]] = 'A';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'B';
                    }
                    sum++;
                }else{
                    ans[a[ind][0]] = 'B';
                    for(int j = 1; j < a[ind].size(); j++){
                        ans[a[ind][j]] = 'A';
                    }
                    sum--;
                }
            }
        }
    }
    ans[n] = '\0';
    if(sum == 0){
        cout<<"YES"<<endl;
        cout<<string(ans)<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}