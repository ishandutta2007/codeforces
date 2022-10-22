
# Problem B - July 27, 2017

def abs(number):
    if number < 0:
        number *= -1
    return number

x = raw_input().split()
n, a = int(x[0]), int(x[1])

smallestAngle = 180. / n
closestAngle = -1
closestAngleVertex = -1

for x in range(n - 2):
    angle = (x + 1) * smallestAngle
    min = abs(angle - a)
    if min < closestAngle or closestAngle == -1:
        closestAngle = min
        closestAngleVertex = x + 3

print '2 1 ' + str(closestAngleVertex)