#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

int n, m;
double k;
map<string, int> result;

int main(){
    cin >> n >> m >> k;
    result.clear();
    for(int i = 0; i < n; ++ i){
        string name;
        int value;
        cin >> name >> value;
        int newValue = (int)floor(value * k + EPS);
        if(newValue >= 100){
            result[name] += newValue;
        }
    }
    for(int i = 0; i < m; ++ i){
        string name;
        cin >> name;
        result[name] += 0;
    }
    cout << (int)result.size() << endl;
    for(map<string, int>::iterator iter = result.begin(); iter != result.end(); ++ iter){
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}