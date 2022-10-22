#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int carPos[1005];
vector<pair<int, int> > car;

int main()
{
    int L, b, f;
    cin >> L >> f >> b;
    int n;
    cin >> n;
    for(int i=0; i < n; ++i){
        sort(car.begin(), car.end());
        int t;
        cin >> t;
        if(t == 1){
            int l;
            cin >> l;
            int J=-1, X;
            if(l > L){
                cout << "-1\n";
                continue;
            }
            if(car.empty() || car[0].first-b >= l){
                carPos[i]=0;
                J=0;
                X=0;
            }
            else{
            for(int j=0; j < car.size(); ++j){
                int x=car[j].first+car[j].second+f;
                if(x+l > L)
                    break;
                if(j == car.size()-1 || car[j+1].first >= x+b+l){
                    X=x;
                    J=j;break;
                }
            }}
            if(J == -1){
                cout << "-1\n";
            }
            else{
                car.push_back(make_pair(X, l));
                carPos[i]=X;
                cout << X << "\n";
            }
        }
        else{
            int ind;
            cin >> ind;
            --ind;
            for(int j=0; j < car.size(); ++j){
                if(car[j].first == carPos[ind]){
                    car.erase(car.begin()+j);
                    break;
                }
            }
        }
    }
    return 0;
}