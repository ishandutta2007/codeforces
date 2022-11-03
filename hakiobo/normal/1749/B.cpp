#include <iostream>
 
int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long hp[200001];
    int spell[200001];
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> hp[j];
        }
        for(int j = 0; j < n; j++){
            cin >> spell[j];
        }
        int first = 0;
        int last = n-1;
        long long total = 0;
        if(n == 1) total = hp[0];
        while(first < last){
            if(abs(first - last) == 1){
                total += hp[first] + hp[last] + min(spell[first], spell[last]);
                break;
            }
            if(spell[first] < spell[last]){
                total += hp[first++];
                hp[first] += spell[first-1];
            } else {
                total += hp[last--];
                hp[last] += spell[last+1];
            }
        }
        cout << total << '\n';
    }
    
}