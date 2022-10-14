x = ' 0'
y = ' 1'
z = ' 2 3 4 5 6 7 8 9'

def move(x):
    print("next{}".format(x), flush=True)
    return int(input().split()[0])

while [move(x), move(x+y)][1] == 3:
    pass
while move(x+y+z) == 2:
    pass
print('done')