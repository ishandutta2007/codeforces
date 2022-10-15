var n = +readline();
var a = readline().split(' ').map(function(v) { return +v; });
var groups = [];
for (var i = n-1; i >= 0; i--) {
    var knt = a[i]; 
    for (var j = 0; j < knt; j++) {
        groups.push(i+1);
    }
    for (var j = 0; j <= i; j++) {
        a[i-j] -= knt * (j+1);
    }
}
var res = "";
var c = 'a';
for (var i = 0; i < groups.length; i++) {
    for (var j = 0; j < groups[i]; j++) {
        res += c;
    }
    c = (c == 'a') ? 'b' : 'a';
}
print(res);