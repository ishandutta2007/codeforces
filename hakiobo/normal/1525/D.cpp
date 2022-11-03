#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int armChairs, i=0;
    cin >> armChairs;
    int occupied[armChairs >> 1] = { -1 }, chairs[armChairs] = { 0 }, people = 0;
    while (i < armChairs){
        cin >> chairs[i];
        if (chairs[i] == 1){
                occupied[people++] = i;
        }
        i++;
    }
    int  second_i, minimalArray[armChairs+1][people + 1] = { INT32_MAX };
    for(i = 0; i <= armChairs; i++){
        for(second_i = 0; second_i <= people; second_i++){
            minimalArray[i][second_i] = INT32_MAX;
        }
    }
    minimalArray[0][0] = 0;
    for (i=1; i <= armChairs; i++){ 
        minimalArray[i][0] = 0;  // as we havent look at any people so first i chairs cost 0
        for (second_i=1; second_i <= people; second_i++){
            minimalArray[i][second_i] = minimalArray[i-1][second_i];  // if you can move second_i person previously you can move that second_i person to i+1 chair with same cost
            if (chairs[i-1] == 0 and minimalArray[i-1][second_i - 1] != INT32_MAX){  // 
                minimalArray[i][second_i] = min(minimalArray[i][second_i],minimalArray[i-1][second_i-1] + abs(occupied[second_i-1] - (i-1)));
            }
        }
    }
    cout << minimalArray[armChairs][people];
}