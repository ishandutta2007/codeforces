#include <iostream>
using namespace std;

int main() {
    int p;
    cin >>p;
    int a=0,b=0,c=0,d=0,count=0,temp;
    for(int i=1;i<=p;i++){
        cin >> temp;
        switch (temp){
            case 1 : a++; break;
            case 2 : b++; break;
            case 3 : c++; break;
            case 4 : d++; break;
        }
    }
    count=count+d+c;
    if(a>c)a=a-c;
    else a=0;
    if((a+ b*2)%4==0)
        count=count+ (a+ b*2)/4;
    
    else {
        count=count+ (a+ b*2)/4 + 1;}
	cout<< count;

	
	return 0;
}