#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
using namespace std;

void rage_quit(){
    cout<<"0";
    exit(0);
}
int main(){
    string s;
    cin>>s;
    deque<char> dq;
    
    for (int x=0;x<s.size();x++){
        dq.push_back(s[x]);
    }
    
    int last;
    char curr;
    while (!dq.empty()){
        curr=dq.front();
        last=0;
        if (dq.back()!=curr) rage_quit();
        
        while (!dq.empty() && dq.front()==curr) dq.pop_front(), last++;
        while (!dq.empty() && dq.back()==curr) dq.pop_back(), last++;
        
        if (dq.empty()){
            if (last<2) rage_quit();
            cout<<last+1;
        }
        else if (last<3) rage_quit();
    }
}