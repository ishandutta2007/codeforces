#include <bits/stdc++.h>

using namespace std;

//std::priority_queue<int, std::vector<int>, std::greater<int> > q;
//bool myfunction (int i,int j) { return (i<j); }
//std::sort (myvector.begin()+4, myvector.end(), myfunction);


bool myfunction (pair<int,int> i,pair<int,int> j) {
        return (i.first>j.first);
     }

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> arrT(n+1,0);
    vector<int> arrF(n+1,0);
    vector<pair<bool,int> > yuv;

    char tem;int num;
    int fal=0;

    for(int i=0;i<n;i++){
        cin>>tem>>num;

        if(tem=='+'){
            yuv.push_back(make_pair(true,num));

            arrT[num]++;
        }else{
            yuv.push_back(make_pair(false,num));
            fal++;
            arrF[num]++;
        }
    }

    vector<bool> canBe(n+1,0);
    int good=0;
    for(int i=1;i<=n;i++){
        if((fal-arrF[i]+arrT[i])==m){
            canBe[i]=true;
            good++;
        }
    }

    for(int i=0;i<n;i++){
        if(yuv[i].first==true){
            if(canBe[yuv[i].second]==1){
                if(good==1){
                    cout<<"Truth"<<endl;
                    continue;
                }else{
                    cout<<"Not defined"<<endl;
                    continue;
                }
            }else{
                    cout<<"Lie"<<endl;
                    continue;
            }
        }else{
            if(canBe[yuv[i].second]==1){
                if(good==1){
                    cout<<"Lie"<<endl;
                    continue;
                }else{
                    cout<<"Not defined"<<endl;
                    continue;
                }
            }else{
                cout<<"Truth"<<endl;
                    continue;
            }
        }
    }


    return 0;
}