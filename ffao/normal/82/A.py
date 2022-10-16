fila = [("Sheldon", 1), ("Leonard", 1), ("Penny", 1), ("Rajesh", 1), ("Howard", 1)]

N = int(raw_input())

while True:
    frente = fila.pop(0)

    if N <= frente[1]:
        print frente[0]
        break

    N -= frente[1]
    fila.append( (frente[0], frente[1]*2) )